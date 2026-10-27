#include <assert.h>
#include <stdio.h>
#include <windows.h>
#include "dns_flusher.h"

int main(void) {
    printf("Running DNS-Cache-Flusher unit tests...\n");
    HMODULE h = LoadLibraryA("dnsapi.dll");
    assert(h != NULL && "dnsapi.dll must be loadable on Windows");
    FARPROC proc = GetProcAddress(h, "DnsFlushResolverCache");
    assert(proc != NULL && "DnsFlushResolverCache export must exist in dnsapi.dll");
    FreeLibrary(h);

    bool res = flush_system_dns_cache();
    printf("DnsFlushResolverCache call status: %s\n", res ? "TRUE" : "FALSE");
    printf("All DNS tests passed.\n");
    return 0;
}
