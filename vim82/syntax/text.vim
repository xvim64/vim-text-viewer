" Vim syntax file
" Language: TEXT
" Maintainer:
" Last Change:

" Quit when a (custom) syntax file was already loaded
if exists("b:current_syntax")
  finish
endif

syn keyword  textTodo     TODO README LOG NOTICE ERROR WARNING
syn match    textTitle    "^\s*#.*"
syn match    textChapter  '^\c\s*\(ch\|chapter\|챕터\)\s*\d\+\>'
syn match    textChapter  '^\c\s*[제]\?\s*\d\+\s*[장화.,|\-:]'
syn match    textChapter  '^\c\s*\(제목\|프롤로그\|에필로그\|후기\|부록\|title\|prologue\|epilogue\|supplement\)\>'
syn match    textComment  "^\/\/.*$"
syn match    textComment  "\s\+\/\/.*$"
syn match    textLine     "\(-\|=\|+\|_\|\*\)\{5,}"
syn match    textBrace    "\[.\{-}\]"


" Define the default highlighting.
" Only used when an item doesn't have highlighting yet
hi def link  textTodo     Todo
hi def link  textTitle    Title
hi def link  textChapter  Title
hi def link  textComment  Constant
hi def link  textLine     CursorLineNr
hi def link  textBrace    Function

let b:current_syntax = "text"

" vim: ts=8 sw=2
