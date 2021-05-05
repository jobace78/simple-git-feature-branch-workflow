[alias]

  feature-to-infinity-and-beyond-no-reset = "!f() { \
    : git checkout ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; exit 1; fi; done; \
    echo '-- THIS ALIAS IS DEPRECATED --'; \
    }; f"
