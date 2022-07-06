[alias]

  feature-begin = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git feature-begin <FEATURE NAME>...'; \
    else \
      feature_name=$(if echo "${1}" | grep -q 'feature/'; then echo "${*}" | tr ' ' '-'; else echo feature/"${*}" | tr ' ' '-'; fi); \
      git fetch origin --prune && \
      git checkout master && \
      git branch "${feature_name:?}" && \
      git checkout "${feature_name:?}"; \
    fi; \
    }; f"
