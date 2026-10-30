# DNS-Cache-Flusher

<div align="center">

![Platform](https://img.shields.io/badge/Platform-Windows-0078D4?style=flat-square&logo=windows)
![Language](https://img.shields.io/badge/Language-C11-A8B9CC?style=flat-square&logo=c)
![License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=flat-square)

**Мгновенный нативный сброс локального DNS-кэша Windows без вызова `ipconfig /flushdns`.**  
*Прямой вызов экспорта `DnsFlushResolverCache` из системной библиотеки `dnsapi.dll`.*

</div>

---

## Архитектура

- Обычный вызов `ipconfig /flushdns` порождает процесс `cmd.exe` или `ipconfig.exe`, вызывая дискретный оверхед.
- `DNS-Cache-Flusher` динамически подгружает `dnsapi.dll` и вызывает недокументированную точку входа `DnsFlushResolverCache()` напрямую в текущем процессе.

## Сборка и тесты

```powershell
gcc -O2 -Isrc src/dns_flusher.c tests/test_main.c -o dns_tests.exe
.\dns_tests.exe
```

## Лицензия
MIT

<!-- verified: 2026-10-30 -->