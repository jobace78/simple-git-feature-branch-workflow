[alias]

  feature-clean = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting."; exit 1; fi; done; \
    git branch --list 'feature/*' --merged|xargs git branch --delete 2> /dev/null && \
    git gc --auto --quiet; \
    }; f"
