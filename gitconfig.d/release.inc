[alias]

  release = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git release <RELEASE NAME>...'; \
    else \
      git fetch origin --prune-tags --tags && \
      git tag "${1}" "${2:-origin/master}" && \
      git push origin "${1}"; \
    fi; \
    }; f"
