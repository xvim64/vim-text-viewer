# Vim 텍스트 뷰어는

Vim 에 고정폭 외의 **가변폭 한글 폰트**

깔끔한 **전체화면**

아름다운 색상테마와 **투명화**

글을 작성할 수 있는 **편집모드**와

독서전용 모드인 **뷰어모드**를 지원하는

**한국어 사용자**를 위한 **Vim** 입니다.



# 프로그램 종료는 F4  입니다

Vim 텍스트 뷰어는 Vim 입니다.

전체화면으로 실행되기 때문에 종료할 수 있는 버튼도 없습니다.

종료는 F4 입니다.

강제 종료는 A+F4 입니다.

:q<엔터> 로도 종료할 수 있습니다.

단축키에 대하나 보다 자세한 내용은 아래 **단축키 (+ 대용량 파일 지원)**에서 확인하세요.



# 추가 폰트를 설치하세요

VimView/fonts 폴더안의 otf, ttf 폰트 파일을 설치해야 추가된 영문/한글 폰트를 사용할 수 있습니다.

설정파일(config/\_vimrc.txt) 에서

let s:bFontListAuto = 1 (또는 0)

에서 값이 1 이면 C:/Windows/Fonts 에서 사용가능한 폰트로 폰트 목록을 자동으로 구성하기 때문에 포터블로 사용할 수 있습니다.

0 이면 사용할 폰트 목록을 사용자가 직접 구성해야합니다.

폰트 관련 설정은 아래의 설정 변경 동영상을 참고하세요.



# 중요한 파일은 작업전에 항상 원본의 복사본을 마련해두세요

Vim 텍스트 뷰어는 뷰어로서의 기능뿐만 아니라 Vim 의 편집기능도 같이 지원합니다.

뷰어모드에서 기본적인 편집키를 막아뒀지만 Vim 이 워낙 방대하기 때문에 그래도 샛길이 있을 수 있습니다.

또한 Vim 에 익숙하지 않을 경우 잘못된 키 입력으로 인해 중요한 파일을 삭제하거나 변경하는 일이 발생할 수 있습니다.

중요한 파일이라면 작업전에 항상 원본의 복사본을 마련해두세요.



# 보다 많은 한글 폰트를 지원합니다

Vim 은 guifont, guifontwide 두 가지 옵션을 통해 영문과 한글에 각기 다른 고정폭 폰트만을 지정할 수 있습니다.

하지만 Vim 을 빌드할 때 FEAT\_PROPORTIONAL\_FONTS 기능을 활성화하면 guifontwide 에 고정폭 폰트인 돋움체, 굴림체, 바탕체, 궁서체 외에도 가변폭 한글 폰트를 사용할 수 있습니다.

guifont 에는 고정폭 영문 폰트를, guifontwide 에는 가변폭 한글 폰트를 설정하면 Hack + Poor Story, Ubuntu Mono + Gowun Dodum 같은 영문과 한글에 각기 다른 미려한 폰트간의 조합이 가능합니다.

Vim 에서 한글 폰트 부족으로 아쉬워하셨던 분들에게 도움이 되기를 바랍니다.



# 글쓰기에 좋습니다.

Vim 텍스트 뷰어는 Vim 입니다.

Vim 에서는 프로그래밍도 가능하기 때문에 글자만 필요한 일반적인 글쓰기에 Vim 을 사용할 경우 과하면 과했지 부족함은 전혀 없습니다.

이러한 Vim 에 전체화면, 투명화, 가변폭 한글 폰트 지원을 추가했기 때문에 더욱 미려한 환경에서 글을 쓰는 게 가능합니다.

여기에 화면 분할, 검색, 이동, 치환, 정규식, 매크로를 지원하기 때문에 문서를 효율적으로 다룰 수 있습니다.



# 단축키 (+ 대용량 파일 지원)

Vim 은 GB 단위의 대용량 텍스트 파일을 편집할 수 있으며 대용량 파일에서도 빠르게 작동합니다.

아래 영상은 GB 단위는 아니지만 308 MB의 **대용량 텍스트 파일**에서 **단축키**를 테스트 하는 영상입니다.

일반적인 환경에서는 보기 힘든 수백 MB 의 대용량 텍스트 파일이지만 Vim (텍스트 뷰어)에서는 시간지연 없이 빠르게 작동합니다.

단축키에 대한 더 자세한 사항은 MyTXT/단축키.txt 를 참고하세요.

[![단축키+명령어+대용량파일지원](https://img.youtube.com/vi/_f6WBFvybjA/0.jpg)](https://youtu.be/_f6WBFvybjA)

- 단축키

	뷰어모드 <-> 편집모드 전환 : F1

	파일 탐색 : F2

	변경사항 저장 : F3

	프로그램 종료 : F4

	투명화 : S-F5

	무작위 생성 색상테마 : F5

	색상테마 변경 : F6

	한글 폰트 변경 : F7

	줄 번호 : F8

	검색 구문 색상 강조 해제 : F9

	전체화면 <-> 최대화, 부분 전체화면 : A-F11

	부분 전체화면 : S-C-F10/F11/F12

	폰트 크기 변경 : F10, S-F10, F11, S-F11, F12, S-F12



# 설정 변경

Vim 텍스트 뷰어는 Vim 이기 때문에 다른 윈도우 프로그램과 같은 설정 변경을 위한 윈도우창을 제공하지 않습니다.

설정을 변경하려면 Vim 설정파일인 config/\_vimrc.txt 를 Vim 텍스트 뷰어의 편집모드나 윈도우 메모장 같은 텍스트 편집기로 열여서 수정해야합니다.

[![설정 변경](https://img.youtube.com/vi/3Jvz2A4xdmM/0.jpg)](https://youtu.be/3Jvz2A4xdmM)



# 지원 기능

- 텍스트 파일 문서 뷰어 지원

- 텍스트 파일 문서 편집 지원

	Vim 고유 편집모드
	Easy Vim 편집모드
	외부 편집기

- 가변폭 폰트 지원 (화면 출력은 고정폭)

- 대용량 파일 지원

	32비트 : 2GB 까지 지원
	64비트 : 사용가능한 스왑파일 용량에 따라 결정

- 여러 [인코딩](http://vimdoc.sourceforge.net/htmldoc/mbyte.html#encoding-values) 지원

	cp949
	utf-8
	utf-16le
	...

- 색상테마 지원

	빔색상테마 : solarized 같은 프리셋 색상파일
	사용자색상테마 : 글씨색/배경색 직접 지정
	무작위생성색상테마 : 글씨색/배경색 무작위 생성

- 전체화면 지원

- 부분 전체화면 지원 (수직/수평 1/2)

- 투명화 지원

- 물리적 한계치까지 무제한 다단 지원



# 뷰어모드

뷰어모드는 Vim 편집모드(C-F1)의 Normal 모드에서 **깜빡거리는 커서 제거, 페이지 넘김시 문장 중복 제거, 긴 문장을 여러줄에 표시**를 적용한 **독서 전용모드**입니다. 뷰어모드에서는 페이지 넘김인 페이지 업/다운 외에 편집에 쓰이는 스페이스, 엔터, 방향키도 페이지 넘김에 할당해서 보다 편리하게 문서를 넘길 수 있도록 했습니다.



# 편집모드

Vim 자체의 편집기능 외에도 Vim 을 메모장처럼 간단히 쓸 수 있는 Easy Vim 기능과 외부 편집기 실행 기능을 추가했습니다.

- Vim 편집모드 (C-F1)

	뷰어모드를 적용하지 않은 본래의 고급 텍스트 편집기인 Vim 입니다.
	Vim 을 배우려는 사용자와 Vim 에 익숙한 사용자를 위한 편집모드입니다.
	Vim 만의 독특한 모드와 고유의 키바인딩 때문에 Vim 을 처음 접하는 사용자는 어느정도 Vim 의 사용법에 대한 학습을 필요로합니다.

- Easy Vim 편집모드 (F1)

	Vim 에 insertmode 가 적용된 Vim 입니다.
	Vim 을 윈도우 메모장처럼 사용할 수 있어 Vim 을 처음 접하는 사용자라도 쉽게 문서를 편집할 수 있습니다.
	하지만 Vim 의 기능이 제약되기 때문에 본래 Vim 의 키바인딩에 익숙한 사용자의 경우 오히려 더 불편할 수 있습니다.

- 외부 편집기 실행 (A-F1)

	파일 편집시 외부 프로그램을 이용합니다.
	Vim 에 어려움을 느끼는 사용자와 다른 텍스트 편집 프로그램에 익숙한 사용자를 위한 기능입니다.
	텍스트 문서를 다룰 수 있는 프로그램이라면 뷰어, 편집기, 기타 등등 그 어떤 것이든 사용자 마음대로 설정할 수 있습니다.
	기본값은 윈도우 메모장입니다.



# 전체화면

텍스트 윈도우만을 화면에 표시합니다.

글씨와 배경만 표시되기 때문에 심플한 Vim 을 더욱 심플하게 만듭니다.



# 부분 전체화면

수직/수평 1/2 전체화면을 지원합니다.

모니터 해상도가 커서 전체화면에서 왼편에서만 작업하기 힘든 경우 사용하면 좋습니다.



# 투명화

단색 배경에 의한 눈의 피로를 줄이고 미려한 폰트, 컬러풀한 색상테마, 심플한 전체화면과 어울려 Vim 텍스트 뷰어를 더욱 아릅답게 만듭니다.



# 무제한 다단 (화면분할)

Vim 텍스트 뷰어의 다단 기능은 Vim 의 화면 분할 기능과 Vim 의 매크로를 이용해서 구현했기 때문에 화면 해상도에 따라 융통성있게 필요한 만큼 화면을 분할하는 것이 가능합니다.

화면에 물리적인 공간만 허용되면 10 분할 및 그 이상도 가능합니다.

S+F1/F2/F3/F4, S+C+F1/F2/F3/F4 키에 화면 1~8 분할을 지정했습니다

화면 8 분할을 넘어 그 이상인 10 분할을 하고 싶다면 ":Ns 10" 명령어를 실행하거나 config/\_vimrc.txt 에서 "let s:nKeyNSplit = [1,2,3,4,5,6,7,8]" 에서 해당 분할키에 할당된 분할수를 조절할 수 있습니다.



# 3 종류의 색상테마

- 빔색상테마

	solarized, gruvbox, molokai, jellybeans, monokai 같은 색상 정보를 담고 있는 색상 설정 파일입니다. 일반 텍스트 파일 뿐만 아니라 C/C++, Python, HTML, MD(Markdown) 같이 특정 키워드를 강조하기 위한 문서 파일에 이용합니다.

- 사용자색상테마

	텍스트 뷰어에 사용할 글씨색-배경색을 직접 지정해서 사용할 수 있습니다. 글씨색-배경색만 필요한 일반 텍스트 파일에 이용할 수 있습니다.

- 무작위생성색상테마

	텍스트 뷰어에 사용할 글씨색-배경색을 무작위로 생성합니다. 키는 F5 입니다. 계속 누르다보면 독특하거나 색다른 색상이 나옵니다. 글씨색-배경색만 필요한 일반 텍스트 파일에 이용하면 좋습니다.



# 북마크

Vim 텍스트 뷰어는 파일을 열 때 이전에 읽었던 마지막 위치를 복원합니다. (이 기능이 불필요한 경우 설정파일에서 이를 비활성화할 수 있습니다.)

북마크 저장은 각각의 파일마다 a-z 까지 북마크를 지정할 수 있으며 지정은 ma, 북마크 이동은 'a 입니다.



# 지원 OS

윈도우 XP, Vista, 7, 8, 10, 11

윈도우 XP 에서도 잘 작동합니다.

[![XP](https://img.youtube.com/vi/AQb8VKZ5sF8/0.jpg)](https://youtu.be/AQb8VKZ5sF8)



# 구성 부분 설명

- \_vimrc.txt

	본래의 Vim 을 Vim 텍스트 뷰어로 변환시키는 기능을 담고 있는 Vim 텍스트 뷰어의 설정파일입니다.

- gvimfullscreen.c (gvimfullscreen32.dll, gvimfullscreen64.dll)

	Vim 텍스트 뷰어에 풀스크린과 투명화를 지원합니다.

- \_VimView.ico

	VimView.exe 파일에 표시되는 Vim 텍스트 뷰어의 아이콘 파일입니다.

- VimView.c, VimView.exe

	\_vimrc.txt 를 설정파일로 해서 gvim.exe 를 실행합니다.

- gvim.exe

	가변폭 한글 폰트, 상단 여백 및 Windows XP 를 지원하기 위해 Visual Studio 2013 Community Edition 에서 Vim 소스코드를 컴파일한 Vim 실행파일입니다.
	VimView.exe 가 아닌 vim82/gvim.exe 를 실행할 경우 설정파일을 읽어들이지 않기 때문에 Vim 텍스트 뷰어가 아닌 본래의 Vim 으로 작동합니다.

- text.vim

	텍스트 문서의 특정 구문에 색상강조(하이라이팅)를 지원합니다.
	텍스트 문서의 색상강조를 원하지 않는 경우 vim82/syntax/text.vim 을 삭제하거나 정규식을 이용해서 색상강조가 적용되는 문장을 변경할 수 있습니다.

- 영문 고정폭 폰트

	Hack, JetBrains Mono, Ubunto Mono, Nova Mono, Fira Code Retina

- 한글 고정폭 폰트 (고정폭 영문 포함)

	D2Coding

- 한글 가변폭 폰트

	Poor Story, 네이버 마루부리 및 나눔글꼴, 리디바탕, 삼립호빵체, 프리텐다드(Inter + 본고딕), 함초롬체, Gugi, SunFlower, 꼬미, 반달이, 고운 돋움, 고운 바탕

- 색상테마 파일

	solarized, molokai, monokai, gruvbox, jellybeans



# 빌드 (컴파일)

Vim 에 가변폭 폰트 지원과 상단여백을 추가했기 때문에 Vim 텍스트 뷰어에서 사용하는 설정파일은 Vim 홈페이지에서 공식적으로 배포하는 Vim 과 호환되지 않습니다.

빌드시에는 상단 여백 패치를 먼저 적용한 후 makefile 을 실행하세요.

- 상단 여백 패치 적용

	Vim 텍스트 뷰어의 src/build/patch/ypadding 의 gui.c.patch, option.h.patch, optiondefs.h.patch 를 GitHub 에서 내려받은 Vim 의 src 폴더에 적용합니다.
	패치를 적용하기 위해서는 윈도우용 git 에 있는 patch.exe 를 필요로 합니다.

- 가변폭 폰트 지원 활성화

	GitHub 에서 내려받은 Vim 의 src 폴더에서 상단 여백 패치를 적용후 빌드시 FEAT\_PROPORTIONAL\_FONTS 매크로를 추가합니다.
	Visual Studio 2013 을 이용해서 빌드할 경우 src/build/make/vs2013/vs2013_x64.cmd 를 참고하세요.
	MSYS2 에서 gcc 를 이용해 빌드할 경우 src/build/make/msys2/msys64.cmd 를 참고하세요.



# 알려진 이슈들

- Vim 은 글자를 고정폭으로 표시합니다. 가변폭 폰트를 사용하더라도 화면 표시는 고정폭입니다.

- Vim 텍스트 뷰어의 무제한 다단은 Vim 의 vsplit 명령어와 매크로를 이용해 구현되었습니다. 다단에서 각각의 버퍼는 동일한 파일을 공유하지만 독립적이기도 합니다. 따라서 마우스 휠을 돌리거나 방향키를 이용할 경우 특정 버퍼에만 효과가 발생하여 다단이 흐트러질 수 있습니다. 뷰어모드에서는 단점이 될 수 있지만 편집모드에서는 각 버퍼에서 따로 작업할 수 있기 때문에 대단히 유용합니다. 다단이 흐트러질 경우 같은 다단키를 다시 한 번 누르면 편집모드에서는 해당 버퍼를 기준으로 다단이 재정렬되고 뷰어모드에서는 맨 왼쪽 버퍼를 기준으로 다단이 재정렬됩니다.

- 부분 전체화면 등에서 큰 글자를 사용할 경우, 매크로로 이루어진 명령어 실행시 알림 메시지가 길어서, 하단에 사용자 입력을 요구하는 경우, 매크로 명령어의 일부 문자가 이에 이용되어 오작동하는 경우가 발생할 수 있습니다. 이를 방지하려고 최대한 노력했지만 Vim 의 특성이라 어쩔 수 없는 경우도 있습니다. 그럴 때는 글자 크기를 줄여서 사용하세요.

- 영문과 한글에 각기 다른 폰트를 사용했기 때문에 맑은 고딕, 고운 돋움, 고운 바탕의 경우 한글이 영문보다 낮은 위치에서 출력됩니다. 영문과 한글이 같이 포함된 문서라면 영문이 한글의 윗첨자처럼 보일 수 있습니다.



# 라이선스 및 출처

Vim 텍스트 뷰어는 각기 다른 라이선스를 갖는 여러 부분으로 구성되어 있습니다.

Vim 텍스트 뷰어의 핵심인 \_vimrc.txt 와 Vim 텍스트 뷰어의 아이콘 파일인 VimView.ico 는 [GPL-2.0 License](https://github.com/xvim64/vim-text-viewer/blob/main/LICENSE) 라이선스를 따릅니다.

Vim 텍스트 뷰어의 VimView.c, text.vim 은 Vim 텍스트 뷰어의 구성 부분이긴 하지만 라이선스를 명기할 정도는 아니어서 GPL-2.0 License 에서 제외합니다.

Vim 텍스트 뷰어에 전체화면과 투명화를 지원하기 위해 변경한 gvimfullscreen.c 는 Derek McLoughlin's [gVimFullScreen](https://github.com/derekmcloughlin/gvimfullscreen_win32#readme) 과 Yasuhiro Matsumoto (a.k.a mattn)'s [VimTweak](https://github.com/mattn/vimtweak#license) 에서 채택한 라이선스를 따릅니다.

VimView.c, gvimfullscreen.c 를 컴파일한 VimView.exe, gvimfullscreen.dll 및 가변폭 한글 폰트를 지원하는 gvim.exe 는 Windows XP 도 지원하기 위해 Visual Studio 2013 Community Edition 을 이용해 컴파일 되었습니다.

Vim 텍스트 뷰어에 포함된 폰트는 Open Font License, Ubuntu Font License, 안심 글꼴 라이선스 등 사용 및 배포에 제약이 적은 폰트 위주로 구성하였습니다. 단 함초롬체의 경우 사용자들은 함초롬체를 자유롭게 배포할 수 있으나, 상업적인 목적으로는 배포 및 수정할 수 없습니다.

- [Vim 설치파일](https://github.com/vim/vim-win32-installer/releases)
- [Vim 소스코드](https://github.com/vim/vim)
- [Vim 라이선스](https://github.com/vim/vim/blob/master/LICENSE)

- [gVimFullScreen](https://github.com/derekmcloughlin/gvimfullscreen_win32)
- [gVimFullScreen 라이선스](https://github.com/derekmcloughlin/gvimfullscreen_win32#readme)

- [VimTweak](https://github.com/mattn/vimtweak)
- [VimTweak 라이선스](https://github.com/mattn/vimtweak#license)

- [Visual Studio 2013 Community Edition](https://visualstudio.microsoft.com/ko/vs/older-downloads/)
- [Visual Studio 2013 Community Edition 라이선스](https://visualstudio.microsoft.com/license-terms/dn877550/)

- [solarized](https://github.com/altercation/vim-colors-solarized)
- [solarized 라이선스](https://github.com/altercation/vim-colors-solarized#license)

- [molokai](https://github.com/tomasr/molokai)
- [molokai 라이선스](https://github.com/tomasr/molokai/blob/master/LICENSE.md)

- [monokai](https://github.com/sickill/vim-monokai)
- [monokai 라이선스](https://github.com/sickill/vim-monokai/blob/master/LICENSE.txt)

- [gruvbox](https://github.com/morhetz/gruvbox)
- [gruvbox 라이선스](https://github.com/morhetz/gruvbox#license)

- [jellybeans](https://github.com/nanotech/jellybeans.vim)
- [jellybeans 라이선스](https://www.mit.edu/~amini/LICENSE.md)

- [Hack](https://github.com/source-foundry/Hack)
- [Hack 라이선스](https://github.com/source-foundry/Hack/blob/master/LICENSE.md)

- [JetBrains Mono](https://github.com/JetBrains/JetBrainsMono)
- [JetBrains Mono 라이선스](https://github.com/JetBrains/JetBrainsMono/blob/master/OFL.txt)

- [Ubuntu Mono](https://design.ubuntu.com/font/)
- [Ubuntu Mono 라이선스](https://ubuntu.com/legal/font-licence)

- [NovaMono](https://fonts.google.com/specimen/Nova+Mono?query=nova)
- [NovaMono 라이선스](https://fonts.google.com/specimen/Nova+Mono?query=nova#license)

- [Fira Code Retina](https://github.com/tonsky/FiraCode)
- [Fira Code Retina 라이선스](https://github.com/tonsky/FiraCode/blob/master/LICENSE)

- [D2Coding](https://github.com/naver/d2codingfont)
- [D2Coding 라이선스](https://github.com/naver/d2codingfont/wiki/Open-Font-License)

- [네이버 마루부리 및 나굼글꼴](https://hangeul.naver.com/2017/nanum)
- [네이버 마루부리 및 나굼글꼴 라이선스](https://help.naver.com/support/contents/contents.help?serviceNo=1074&categoryNo=3497)

- [리디바탕 + 라이선스](https://www.ridicorp.com/ridibatang/)

- [삼립호빵체 + 라이선스](http://spcsamlip.co.kr/sandoll-samlip-hopang/)

- [프리텐다드](https://github.com/orioncactus/pretendard)
- [프리텐다드 라이선스](https://github.com/orioncactus/pretendard/blob/main/LICENSE)

- [함초롬체 + 라이선스](https://www.hancom.com/cs_center/csDownload.do)

- [Gugi + 라이선스](https://fonts.google.com/specimen/Gugi?subset=korean)
- [PoorStory + 라이선스](https://fonts.google.com/specimen/Poor+Story?subset=korean)
- [Sunflower + 라이선스](https://fonts.google.com/specimen/Sunflower?subset=korean)

- [반달이 & 꼬미 + 라이선스](https://www.knps.or.kr/portal/bandal/sub01.do)

- [고운 바탕 + 라이선스](https://fonts.google.com/specimen/Gowun+Batang?subset=korean)
- [고운 돋움 + 라이선스](https://fonts.google.com/specimen/Gowun+Dodum?subset=korean)

- [B사감과 러브레터](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9002100&menuNo=200019)
- [내마음 고요히 흐른 봄길 우에](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9000343&menuNo=200019)
- [동백꽃](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9000397&menuNo=200026)
- [메밀꽃 필 무렵](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9001211&menuNo=200019)
- [별 헤는 밤](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9000761&menuNo=200019)
- [봄 봄](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9000404&menuNo=200026)
- [서시](https://gongu.copyright.or.kr/gongu/wrt/wrt/view.do?wrtSn=9000779&menuNo=200019)

