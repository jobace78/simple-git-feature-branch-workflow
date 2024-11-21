[alias]

  feature-from-main = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git feature-from-main <FEATURE NAME>...'; \
    else \
      feature_name=feature/$(echo "${*}" | grep -o '[^/]*$' | tr ' ' '-'); \
      git fetch origin --prune && \
      git checkout main && \
      git branch "${feature_name:?}" && \
      git checkout "${feature_name:?}"; \
    fi; \
    }; f"
