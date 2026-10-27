#include <stdio.h>
#include "dns_flusher.h"

int main(int argc, char* argv[]) {
    printf("[DNS-Cache-Flusher] Native Windows DNS Resolver Cache Purger\n");
    printf("Flushing Windows DNS client resolver cache via dnsapi!DnsFlushResolverCache...\n");

    if (flush_system_dns_cache()) {
        printf("SUCCESS: DNS Resolver Cache successfully flushed.\n");
        return 0;
    } else {
        printf("ERROR: Failed to flush DNS cache (insufficient permissions or resolver offline).\n");
        return 1;
    }
}
