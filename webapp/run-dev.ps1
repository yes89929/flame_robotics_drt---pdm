# PDM web tool dev server: FastAPI (:2940) + Vite (:2941).
# keep this file ASCII-only -- Windows PowerShell fails to parse non-ASCII scripts
# and exits with code 1 without writing a single log line.
#
# Launched by the Task Scheduler task "PDM-web-dev" (never from an agent tool call).
# Logs: webapp\logs\dev.log

$ErrorActionPreference = 'Stop'

# conda is not on the default PowerShell PATH; the API runs via `conda run -n drt-pdm`.
$mf = Join-Path $env:USERPROFILE 'miniforge3'
$env:PATH = "$mf\condabin;$mf\Scripts;$mf;$mf\Library\bin;" + $env:PATH
$env:PYTHONIOENCODING = 'utf-8'

Set-Location -Path $PSScriptRoot
New-Item -ItemType Directory -Force -Path (Join-Path $PSScriptRoot 'logs') | Out-Null
$log = Join-Path $PSScriptRoot 'logs\dev.log'
"==== start $(Get-Date -Format s) ====" | Out-File -FilePath $log -Encoding ascii

# cmd redirection keeps node's UTF-8 bytes as-is (PowerShell 5 redirection would write UTF-16,
# and 2>&1 on a native command turns stderr lines into errors).
cmd /c "npm run dev >> `"$log`" 2>&1"
