// 화면 개발 서버. /api 는 FastAPI(pdm_web, 2940)로 프록시한다.
// 포트 블록 2940~2949 (전역 포트 규칙 4번대): 2940 = API, 2941 = 이 서버.
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

const API_TARGET = process.env.PDM_WEB_API ?? 'http://127.0.0.1:2940'
// 기본 0.0.0.0: 루프백과 Tailscale 모두에서 연다. 노출 범위는 Windows 방화벽이 통제한다.
const WEB_HOST = process.env.PDM_WEB_HOST ?? '0.0.0.0'
const WEB_PORT = Number(process.env.PDM_WEB_PORT ?? 2941)

export default defineConfig({
  plugins: [react()],
  server: {
    host: WEB_HOST,
    port: WEB_PORT,
    strictPort: true,
    proxy: { '/api': { target: API_TARGET, changeOrigin: true } },
  },
})
