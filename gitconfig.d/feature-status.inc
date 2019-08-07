[alias]

  feature-status = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; echo exit 1; fi; done; \
    echo '-- THIS ALIAS IS IN BETA STATE --'; \
    echo; \
    echo '-- merged --'; \
    git branch --all --list 'feature/*' --merged; \
    if [ x"${1}" = xall ]; then \
      echo '-- merged (remote) --'; \
      git branch --all --list '*feature/*' --merged; \
    fi; \
    echo '-- no merged --'; \
    git branch --all --list 'feature/*' --no-merged; \
    if [ x"${1}" = xall ]; then \
      echo '-- no merged (remote) --'; \
      git branch --all --list '*feature/*' --no-merged; \
    fi; \
    }; f"
