# Set up CUDA in OS
import os
os.environ['CUDA_LAUNCH_BLOCKING'] = '1'
# Import libabries
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import numpy as np
import seaborn as sn
import pandas as pd
import torchvision
from torchvision import *
from torch.utils.data import Dataset, DataLoader
from torchvision.io import read_image
import torchvision.transforms as T
from torchvision import datasets, models, transforms
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

import matplotlib.pyplot as plt
import time
import copy

# Ignore warnings
import warnings
warnings.filterwarnings("ignore")


# Setup device agnostic code
device = "cuda" if torch.cuda.is_available() else "cpu"

# Find out if a GPU is available
use_cuda = torch.cuda.is_available()

# Set up path for data after downloading
default_dir = r"C:\Users\User\CD_DL_241210\CD_DL_241210\ws\Skin cancer dataset"
train_dir = default_dir + "/train/"
test_dir = default_dir + "/test/"
train_classa_dir = default_dir + "/train/benign/"
train_classb_dir = default_dir + "/train/malignant/"
test_classa_dir = default_dir + "/test/benign/"
test_classb_dir = default_dir + "/test/malignant/"


# Display image for reference
white_torch = torchvision.io.read_image(default_dir + '/test/benign/1.jpg')
print("This is benign skin cancer")
T.ToPILImage()(white_torch)


# Display image for reference
wh = torchvision.io.read_image(default_dir + '/test/benign/44.jpg')
print("This is malignant skin cancer")
T.ToPILImage()(wh)


# Create transform function
transforms_train = transforms.Compose([
    transforms.Resize((224, 224)),   #must same as here
    transforms.RandomResizedCrop(224),
    transforms.RandomHorizontalFlip(), # data augmentation
    transforms.ToTensor(),
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]) # normalization
])
transforms_test = transforms.Compose([
    transforms.Resize((224, 224)),   #must same as here
     transforms.CenterCrop((224, 224)),
    transforms.ToTensor(),
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
])


# ... existing transforms and ImageFolder creation ...

# Create the full datasets first
train_dataset_raw = datasets.ImageFolder(train_dir, transforms_train)
test_dataset_raw = datasets.ImageFolder(test_dir, transforms_test)

# # Take subsets of the data to get desired sizes
# train_dataset = torch.utils.data.Subset(train_dataset_raw, range(320))
# test_dataset = torch.utils.data.Subset(test_dataset_raw, range(120))

# # Create data loaders
# train_dataloader = torch.utils.data.DataLoader(train_dataset, batch_size=12, shuffle=True, num_workers=0)
# test_dataloader = torch.utils.data.DataLoader(test_dataset, batch_size=12, shuffle=False, num_workers=0)




# ... existing imports ...
import random

# Set random seed for reproducibility
random.seed(42)

# Get total dataset sizes
total_train_size = len(train_dataset_raw)
total_test_size = len(test_dataset_raw)

# Randomly sample indices
train_indices = random.sample(range(total_train_size), 320)
test_indices = random.sample(range(total_test_size), 120)

# Create subsets using random indices
train_dataset = torch.utils.data.Subset(train_dataset_raw, train_indices)
test_dataset = torch.utils.data.Subset(test_dataset_raw, test_indices)

# Create data loaders (unchanged)
train_dataloader = torch.utils.data.DataLoader(train_dataset, batch_size=12, shuffle=True, num_workers=0)
test_dataloader = torch.utils.data.DataLoader(test_dataset, batch_size=12, shuffle=False, num_workers=0)



# print('Train dataset size:', len(train_dataset))
# print('Test dataset size:', len(test_dataset))
# class_names = train_dataset.classes
# print('Class names:', class_names)


# ... existing code ...
print('Train dataset size:', len(train_dataset))
print('Test dataset size:', len(test_dataset))

# Access classes from the original ImageFolder dataset
class_names = train_dataset_raw.classes
print('Class names:', class_names)


plt.rcParams['figure.figsize'] = [12, 8]
plt.rcParams['figure.dpi'] = 60
plt.rcParams.update({'font.size': 20})
def imshow(input, title):
    # torch.Tensor => numpy
    input = input.numpy().transpose((1, 2, 0))
    # undo image normalization
    mean = np.array([0.485, 0.456, 0.406])
    std = np.array([0.229, 0.224, 0.225])
    input = std * input + mean
    input = np.clip(input, 0, 1)
    # display images
    plt.imshow(input)
    plt.title(title)
    plt.show()
# load a batch of train image
iterator = iter(train_dataloader)
# visualize a batch of train image
inputs, classes = next(iterator)
out = torchvision.utils.make_grid(inputs[:4])
imshow(out, title=[class_names[x] for x in classes[:4]])

# model
model = models.resnet50(pretrained=True)


num_features = model.fc.in_features 
print('Number of features from pre-trained model', num_features)


# Add a fully-connected layer for classification
model.fc = nn.Linear(num_features, 2)
model = model.to(device)


# Define loss and optimizer
criterion = nn.CrossEntropyLoss()
# optimizer = optim.SGD(model.parameters(), lr=0.0001, momentum=0.9)

optimizer = torch.optim.Adam(model.parameters(), lr=0.0001)


# Set the random seeds
torch.manual_seed(42)
torch.cuda.manual_seed(42)


#### Train model
train_loss=[]
train_accuary=[]
test_loss=[]
test_accuary=[]

num_epochs = 10   #(set no of epochs)
start_time = time.time() #(for showing time)


# Start loop
for epoch in range(num_epochs): #(loop for every epoch)
    print("Epoch {}/{} running".format(epoch+1, num_epochs)) #(printing message)
    """ Training Phase """
    model.train()    #(training model)
    running_loss = 0.   #(set loss 0)
    running_corrects = 0 
    # load a batch data of images
    for i, (inputs, labels) in enumerate(train_dataloader):
        inputs = inputs.to(device)
        labels = labels.to(device) 
        # forward inputs and get output
        optimizer.zero_grad()
        outputs = model(inputs)
        _, preds = torch.max(outputs, 1)
        loss = criterion(outputs, labels)
        # get loss value and update the network weights
        loss.backward()
        optimizer.step()
        running_loss += loss.item()
        running_corrects += torch.sum(preds == labels.data).item()
    epoch_loss = running_loss / len(train_dataset)
    epoch_acc = running_corrects / len(train_dataset) * 100.
    # Append result
    train_loss.append(epoch_loss)
    train_accuary.append(epoch_acc)
    # Print progress
    print('[Train #{}] Loss: {:.4f} Acc: {:.4f}% Time: {:.4f}s'.format(epoch+1, epoch_loss, epoch_acc, time.time() -start_time))
    """ Testing Phase """
    model.eval()
    with torch.no_grad():
        running_loss = 0.
        running_corrects = 0
        for inputs, labels in test_dataloader:
            inputs = inputs.to(device)
            labels = labels.to(device)
            outputs = model(inputs)
            _, preds = torch.max(outputs, 1)
            loss = criterion(outputs, labels)
            running_loss += loss.item()
            running_corrects += torch.sum(preds == labels.data).item()
        epoch_loss = running_loss / len(test_dataset)
        epoch_acc = running_corrects / len(test_dataset) * 100.
        # Append result
        test_loss.append(epoch_loss)
        test_accuary.append(epoch_acc)
        # Print progress
        print('[Test #{}] Loss: {:.4f} Acc: {:.4f}% Time: {:.4f}s'.format(epoch+1, epoch_loss, epoch_acc, time.time()- start_time))
        
        
        # epoch 30, resnet18 : 14m, optim.SGD(model.parameters(), lr=0.0001, momentum=0.9)
        #epoch 10, resnet50: 13m, optim.SGD(model.parameters(), lr=0.0001, momentum=0.9)
#        [Train #10] Loss: 0.0332 Acc: 83.4375% Time: 784.9627s
# [Test #10] Loss: 0.0395 Acc: 73.3333% Time: 794.9909s

#epoch 10, resnet50: , 14m, adam, 
# [Train #10] Loss: 0.0175 Acc: 93.1250% Time: 881.8872s
# [Test #10] Loss: 0.0645 Acc: 75.8333% Time: 890.8008s


save_path = 'custom-classifier_resnet_18_final.pth'
torch.save(model.state_dict(), save_path)



# Get data to check on the performance of each label
y_pred = []
y_true = []

num_epochs = 30   #(set no of epochs)
start_time = time.time() #(for showing time)
# Start loop
for epoch in range(num_epochs): #(loop for every epoch)
    model.eval()
    with torch.no_grad():
        for inputs, labels in test_dataloader:
            inputs = inputs.to(device)
            labels = labels.to(device)
            outputs = model(inputs) # Feed Network
            outputs = (torch.max(torch.exp(outputs), 1)[1]).data.cpu().numpy()
            y_pred.extend(outputs) # Save Prediction
            labels = labels.data.cpu().numpy()
            y_true.extend(labels) # Save Truth