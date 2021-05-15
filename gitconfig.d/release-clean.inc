[alias]

  release-clean = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    echo '-- THIS ALIAS IS IN BETA STATE --'; \
    echo; \
    git tag --list --merged|xargs git tag --delete 2> /dev/null && \
    git gc --auto --quiet; \
    }; f"
