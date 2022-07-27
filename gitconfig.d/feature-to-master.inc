[alias]

  feature-to-master = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git feature-to-master <FEATURE NAME> [MESSAGE]...'; \
    else \
      feature_name=$(if echo "${1}" | grep -q 'feature/'; then echo "${1}" | tr ' ' '-'; else echo feature/"${1}" | tr ' ' '-'; fi); \
      shift; \
      message="${*}"; \
      git fetch origin --prune && \
      git checkout master && \
      if [ -x "$(command -v gpg)" ] && [ "$(git config commit.gpgsign 2> /dev/null)" = 'true' ]; then \
        git_merge_options='--log --no-ff --signoff'; \
      else \
        git_merge_options='--log --no-ff'; \
      fi; \
      if [ -n \"${message}\" ]; then \
        git merge ${git_merge_options} --message 'Merge branch '"${feature_name:?}"' into master -- '\"${message}\"'' "${feature_name:?}"; \
      else \
        git merge ${git_merge_options} --message 'Merge branch '"${feature_name:?}"' into master' "${feature_name:?}"; \
      fi; \
    fi; \
    }; f"
