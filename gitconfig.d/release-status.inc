[alias]

  release-status = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    echo '-- merged --'; \
    git tag --list --merged; \
    echo '-- no merged --'; \
    git tag --list --no-merged; \
    }; f"
