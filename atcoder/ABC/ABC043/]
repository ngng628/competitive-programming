"文字コード
set fenc=utf-8
set ambiwidth=double
set wildmenu

"バックアップ
set nobackup
set noswapfile

set hidden
set autoread
set noerrorbells
set clipboard=unnamed

"見た目
set number
set virtualedit=onemore
set smartindent
set showmatch
set wildmode=list:longest
set vb t_vb=
syntax on

"タブ
set expandtab
set tabstop=4
set shiftwidth=4

"検索
set ignorecase
set smartcase
set incsearch
set wrapscan
set hlsearch
nmap <Esc><Esc> :nohlsearch<CR><Esc>

filetype plugin indent on

"マウス
if has('mouse')
    set mouse=a
endif

"dein Scripts-----------------------------
if &compatible
  set nocompatible               " Be iMproved
endif

" Required:
set runtimepath+=$HOME/.cache/dein/repos/github.com/Shougo/dein.vim

" Required:
if dein#load_state('$HOME/.cache/dein')
  call dein#begin('$HOME/.cache/dein')

  " Let dein manage dein
  " Required:
  call dein#add('$HOME/.cache/dein/repos/github.com/Shougo/dein.vim')

  " Add or remove your plugins here:
  call dein#add('Shougo/neosnippet.vim')
  call dein#add('Shougo/neosnippet-snippets')

  " You can specify revision/branch/tag.
  call dein#add('Shougo/deol.nvim', { 'rev': '01203d4c9' })

  "
  call dein#add('cohama/lexima.vim')
  call dein#add('Yggdroot/indentLine')
  call dein#add('flazz/vim-colorschemes')
  call dein#add('Lokaltog/vim-powerline')
  call dein#add('fatih/vim-go')
  call dein#add('mattn/sonictemplate-vim')
  call dein#add('Shougo/deoplete.nvim')
  call dein#add('Shougo/neco-vim')
  call dein#add('Shougo/neco-syntax')
  call dein#add('ujihisa/neco-look') 
  call dein#add('scrooloose/nerdtree') 
  call dein#add('KeitaNakamura/highlighter.nvim')
  " Required:
  call dein#end()
  call dein#save_state()
endif

" Required:
filetype plugin indent on
syntax enable

" If you want to install not installed plugins on startup.
if dein#check_install()
  call dein#install()
endif

let g:go_version_warning = 0
let g:sonictemplate_vim_template_dir = [
    \ '~/.config/nvim/template'
    \]
let g:deoplete#enable_at_startup = 1
map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeDirArrows = 1
let g:NERDTreeDirArrowExpandable  = '>'
let g:NERDTreeDirArrowCollapsible = '▼'
let g:highlighter#auto_update = 2
"End dein Scripts-------------------------



