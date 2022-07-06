[alias]

  publish-next = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    git fetch origin --prune && \
    git push --set-upstream origin next; \
    }; f"
