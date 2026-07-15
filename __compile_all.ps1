Get-ChildItem . -File | ForEach-Object {
    if($_.Extension -eq ".c") {
        $Name = $_.BaseName
        Write-Host "Compile $Name ..."
        gcc -o "bin\$Name" "$Name.c"
    }
}
