"""`python -m pdm_web` — API 서버 기동 (기본 127.0.0.1:2940, 화면은 Vite 2941 이 프록시)."""

import os

import uvicorn

from .app import app

if __name__ == "__main__":
    uvicorn.run(
        app,
        host=os.environ.get("PDM_WEB_API_HOST", "127.0.0.1"),
        port=int(os.environ.get("PDM_WEB_API_PORT", "2940")),
    )
