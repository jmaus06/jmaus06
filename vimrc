
"rscheme badwolf " awesome colorscheme
syntax enable " enable syntax processing
set tabstop=4 " number of visual spaces per TAB
set softtabstop=4 " number of spaces in tab when editing
set expandtab " tabs are spaces
set number " show line numbers
set showcmd " show command in bottom bar
set cursorline " highlight current line
set wildmenu " visual autocomplete for command menu
set lazyredraw " redraw only when we need to.
set showmatch " highlight matching [{()}]

set incsearch " search as characters are entered
set hlsearch " highlight matches
nnoremap <leader><space> :nohlsearch<CR>

set foldenable " enable folding
set foldlevelstart=10 " open most folds by default
set foldnestmax=10 " 10 nested fold max

" space open/closes folds
" nnoremap <space> za
" set foldmethod=indent " fold based on indent level
"
" " move vertically by visual line
nnoremap j gj
nnoremap k gk
"
" " move to beginning/end of line
nnoremap B ^
nnoremap E $
"
" " $/^ doesn't do anything
" nnoremap $ <nop>
" nnoremap ^ <nop>
"
" " highlight last inserted text
nnoremap gV `[v`]
"
let mapleader="," " leader is comma
"
" " jk is escape
inoremap jk <esc>
"
" " toggle gundo
nnoremap <leader>u :GundoToggle<CR>
"
" " edit vimrc/zshrc and load vimrc bindings
nnoremap <leader>ev :vsp $MYVIMRC<CR>
nnoremap <leader>ez :vsp ~/.zshrc<CR>
nnoremap <leader>sv :source $MYVIMRC<CR>
"
" " save session
nnoremap <leader>s :mksession<CR>
"
" " open ag.vim
nnoremap <leader>a :Ag
"
" " CtrlP settings
let g:ctrlp_match_window = 'bottom,order:ttb'
let g:ctrlp_switch_buffer = 0
let g:ctrlp_working_path_mode = 0
let g:ctrlp_user_command = 'ag %s -l --nocolor --hidden -g ""'
let g:ctrlp_user_command = 'ag %s -l --nocolor -g ""'
"
"call pathogen#infect() " use pathogen
"call pathogen#runtime_append_all_bundles() " use pathogen
"
" " allows cursor change in tmux mode
if exists('$TMUX')
let &t_SI = "\<Esc>Ptmux;\<Esc>\<Esc>]50;CursorShape=1\x7\<Esc>\\"
let &t_EI = "\<Esc>Ptmux;\<Esc>\<Esc>]50;CursorShape=0\x7\<Esc>\\"
else
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
endif
"
augroup configgroup
autocmd!
autocmd VimEnter * highlight clear SignColumn
autocmd BufWritePre *.php,*.py,*.js,*.txt,*.hs,*.java,*.md
\:call <SID>StripTrailingWhitespaces()
autocmd FileType java setlocal noexpandtab
autocmd FileType java setlocal list
autocmd FileType java setlocal listchars=tab:+\ ,eol:-
autocmd FileType java setlocal formatprg=par\ -w80\ -T4
autocmd FileType php setlocal expandtab
autocmd FileType php setlocal list
autocmd FileType php setlocal listchars=tab:+\ ,eol:-
autocmd FileType php setlocal formatprg=par\ -w80\ -T4
autocmd FileType ruby setlocal tabstop=2
autocmd FileType ruby setlocal shiftwidth=2
autocmd FileType ruby setlocal softtabstop=2
autocmd FileType ruby setlocal commentstring=#\ %s
autocmd FileType python setlocal commentstring=#\ %s
autocmd BufEnter *.cls setlocal filetype=java
autocmd BufEnter *.zsh-theme setlocal filetype=zsh
autocmd BufEnter Makefile setlocal noexpandtab
autocmd BufEnter *.sh setlocal tabstop=2
autocmd BufEnter *.sh setlocal shiftwidth=2
autocmd BufEnter *.sh setlocal softtabstop=2
augroup END
"
set backup
set backupdir=~/.vim-tmp,~/.tmp,~/tmp,/var/tmp,/tmp
set backupskip=/tmp/*,/private/tmp/*
set directory=~/.vim-tmp,~/.tmp,~/tmp,/var/tmp,/tmp
set writebackup
"
" " toggle between number and relativenumber
function! ToggleNumber()
if(&relativenumber == 1)
set norelativenumber
set number
else
set relativenumber
endif
endfunc
"
" " strips trailing whitespace at the end of files. this
" " is called on buffer write in the autogroup above.
function! <SID>StripTrailingWhitespaces()
" save last search & cursor position
let _s=@/
let l = line(".")
let c = col(".")
%s/\s\+$//e
let @/=_s
call cursor(l, c)
endfunction

" Vundle
set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'gmarik/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'L9'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
Plugin 'Valloric/YouCompleteMe'

call vundle#end()
filetype indent on " load filetype-specific indent files

