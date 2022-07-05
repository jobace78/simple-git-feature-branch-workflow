[alias]

  feature-where-is = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1>/dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git feature-where-is <FEATURE NAME>...'; \
    else \
      feature_name=$(if echo "${1}" | grep -q 'feature/'; then echo "${*}" | tr ' ' '-'; else echo feature/"${*}" | tr ' ' '-'; fi); \
      git fetch origin --prune && \
      git branch --all --contains "${feature_name:?}" | grep -v 'feature/'; \
    fi; \
    }; f"
