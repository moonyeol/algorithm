'''A라는 디렉토리 하위에 있는 텍스트 파일(*.txt) 중에서 LIFE IS TOO SHORT 라는 문자열을 포함하고 있는 파일들을 모두 찾을 수 있는 프로그램을 작성하시오.

단, 하위 디렉토리도 포함해서 검색해야 함.'''

import os
import codecs

for root, dirs, files in os.walk('.') :
    for name in files :
        if '.txt' in name :
            f = codecs.open(os.path.join(root,name), 'r', encoding='utf-8')
            txt = f.readlines()
            if 'LIFE IS TOO SHORT' in txt: print(name)
            f.close()
