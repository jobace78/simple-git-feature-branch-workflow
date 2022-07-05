[alias]

  feature-to-next = "!f() { \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1>/dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    if [ x"${1}" = x ]; then \
      echo 'Usage: git feature-to-next <FEATURE NAME> [MESSAGE]...'; \
    else \
      feature_name=$(if echo "${1}" | grep -q 'feature/'; then echo "${1}" | tr ' ' '-'; else echo feature/"${1}" | tr ' ' '-'; fi); \
      shift; \
      message="${*}"; \
      git fetch origin --prune && \
      git checkout next && \
      if [ -n \"${message}\" ]; then \
        if [ -x "$(command -v gpg)" ] && [ "$(git config commit.gpgsign 2>/dev/null)" = 'true' ]; then \
          git merge --log --message 'Merge branch '"${feature_name:?}"' into next ['\"${message}\"']' --no-ff --signoff "${feature_name:?}"; \
        else \
          git merge --log --message 'Merge branch '"${feature_name:?}"' into next ['\"${message}\"']' --no-ff "${feature_name:?}"; \
        fi; \
      else \
        if [ -x "$(command -v gpg)" ] && [ "$(git config commit.gpgsign 2>/dev/null)" = 'true' ]; then \
          git merge --log --message 'Merge branch '"${feature_name:?}"' into next' --no-ff --signoff "${feature_name:?}"; \
        else \
          git merge --log --message 'Merge branch '"${feature_name:?}"' into next' --no-ff "${feature_name:?}"; \
        fi; \
      fi; \
    fi; \
    }; f"
