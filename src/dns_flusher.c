#include <windows.h>
#include "dns_flusher.h"

typedef BOOL(WINAPI* pfnDnsFlushResolverCache)(VOID);

bool flush_system_dns_cache(void) {
    HMODULE hDnsApi = LoadLibraryA("dnsapi.dll");
    if (!hDnsApi) return false;

    pfnDnsFlushResolverCache pfnFlush = 
        (pfnDnsFlushResolverCache)GetProcAddress(hDnsApi, "DnsFlushResolverCache");

    if (!pfnFlush) {
        FreeLibrary(hDnsApi);
        return false;
    }

    BOOL ok = pfnFlush();
    FreeLibrary(hDnsApi);
    return ok != FALSE;
}
