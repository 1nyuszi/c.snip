param($Name)

$CustomCompilationScript = ".\" + $Name + ".ps1"

if (Test-Path $CustomCompilationScript) {
    Write-Host "Compilation with custom script $CustomCompilationScript"
    & $CustomCompilationScript
} else {
    Write-Host "Default compilation"
    gcc -o "bin\$Name" "$Name.c"
}

if ($LastExitCode -eq 0) {
    Write-Host "Compilation succeeded!`n" -ForegroundColor Green
    $Executable = ".\bin\" + $Name + ".exe"
    Write-Host "Running Executable $Executable"
    & $Executable
    if ($LastExitCode -eq 0) {
        Write-Host "Execution succeeded!`n" -ForegroundColor Green
    } else {
        Write-Host "Execution failed with exit code $LastExitCode`n" -ForegroundColor Red
    }
} else {
    Write-Host "Compilation failed with exit code $LastExitCode`n" -ForegroundColor Red
}
