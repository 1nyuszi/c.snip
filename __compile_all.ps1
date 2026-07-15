Get-ChildItem . -File | ForEach-Object {
    if ($_.Extension -eq ".c") {
        $Name = $_.BaseName
        Write-Host "Compile $Name ..."
        gcc -o "bin\$Name" "$Name.c"
        if ($LastExitCode -eq 0) {
            Write-Host "Compilation succeeded!`n" -ForegroundColor Green
        } else {
            Write-Host "Compilation failed with exit code $LastExitCode`n" -ForegroundColor Red
        }
    }
}
