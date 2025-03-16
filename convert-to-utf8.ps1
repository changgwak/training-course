$path = "C:\Users\user\Downloads\ssoop-main\DAY5\"

# 프로젝트 폴더 내 모든 파일 검색 후 특정 확장자만 필터링
Get-ChildItem -Path $path -Recurse | 
Where-Object { $_.Extension -match '\.(cpp|h|cs|md)$' } | 
ForEach-Object {
    $content = Get-Content $_.FullName -Raw
    $content | Set-Content $_.FullName -Encoding utf8
}

# How to Use
# cd "C:\Users\user\Downloads\ssoop-main"
# Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass  
# .\convert-to-utf8.ps1  