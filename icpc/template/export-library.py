import os
from pathlib import Path

output_file_name = 'template_ngng628.md'
library_dir = './library'

doc = [
    '# ICPCライブラリ（んぐ）'
]

for root, _, files in os.walk(library_dir):
    for file in files:
     with open(Path(root) / Path(file)) as f:
       text = f.read()
       doc.append(f'## {Path(file).stem}')
       doc.append('```cpp')
       doc.append(text)
       doc.append('```')
       doc.append('')
       doc.append('<div style="page-break-before:always"></div>')
       doc.append('')

with open(Path(output_file_name), 'w') as f:
    f.write('\n'.join(doc))