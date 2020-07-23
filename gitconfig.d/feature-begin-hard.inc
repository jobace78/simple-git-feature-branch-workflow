[alias]

  feature-begin-hard = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'usage: git feature-begin <feature name>...'; \
    else \
      feature_name=$(if echo "${1}"|grep -q 'feature/'; then echo "${*}"|tr ' ' '-'; else echo feature/"${*}"|tr ' ' '-'; fi); \
      [ -n "${feature_name}" ] || { echo "feature_name was NOT found, exiting..."; exit 1; }; \
      git fetch origin --prune && \
      git checkout master && \
      git reset --hard origin/master && \
      git branch "${feature_name}" && \
      git checkout "${feature_name}"; \
    fi; \
    }; f"
