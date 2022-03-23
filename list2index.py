def write(index): 
  with open('index.md', 'w') as f: 
    f.write('# index\n')
    for tag in sorted(index.keys()): 
      f.write('\n'
              f'## {tag}\n'
              '\n'
              '| problem | difficulty | tags | comments |\n'
              '| :---: | :---: | :---: | :--- |\n')
      for problem in index[tag]['problems']: 
        f.write(f'| {problem[0]} | {problem[1]["difficulty"]} | {problem[1]["raw_tags"]} | {problem[1]["comments"]} |\n')
      for subtag in sorted(index[tag]['subtags'].keys()): 
        f.write('\n'
                f'### {subtag}\n'
                '\n'
                '| problem | difficulty | tags | comments |\n'
                '| :---: | :---: | :---: | :--- |\n')
        for problem in index[tag]['subtags'][subtag]['problems']: 
          f.write(f'| {problem[0]} | {problem[1]["difficulty"]} | {problem[1]["raw_tags"]} | {problem[1]["comments"]} |\n')

def read(): 
  index = {}
  with open('list.md') as f: 
    last = [None, None]
    for line in f.readlines(): 
      line = line.rstrip()
      if line.startswith('- '): 
        if last[0] != None: 
          for tag in last[1]['tags']: 
            if ':' not in tag: 
              index[tag]['problems'].append(last)
            else: 
              [supertag, subtag] = tag.split(':')
              index[supertag]['subtags'][subtag]['problems'].append(last)
        [problem, raw_tags] = line[2:].split(') - ')
        problem += ')'
        parent_tag = ''
        word = ''
        tags = []
        for c in raw_tags: 
          if c == ' ': 
            if word != '': 
              word += c
          elif c == ':': 
            parent_tag = word
            if parent_tag not in index.keys(): 
              index[parent_tag] = {
                'problems': [], 
                'subtags': {}
              }
            tags.append(parent_tag)
            word = ''
          elif c == ',': 
            if word not in index[parent_tag]['subtags'].keys(): 
              index[parent_tag]['subtags'][word] = {
                'problems': []
              }
            tags.append(parent_tag + ':' + word)
            word = ''
          elif c == ';': 
            if parent_tag == '': 
              if word not in index.keys(): 
                index[word] = {
                  'problems': [], 
                  'subtags': {}
                }
              tags.append(word)
            else: 
              if word not in index[parent_tag]['subtags'].keys(): 
                index[parent_tag]['subtags'][word] = {
                  'problems': []
                }
              tags.append(parent_tag + ':' + word)
            parent_tag = ''
            word = ''
          else: 
            word += c
        if word != '': 
          if parent_tag == '': 
            if word not in index.keys(): 
              index[word] = {
                'problems': [], 
                'subtags': {}
              }
            tags.append(word)
          else: 
            if word not in index[parent_tag]['subtags'].keys(): 
              index[parent_tag]['subtags'][word] = {
                'problems': []
              }
            tags.append(parent_tag + ':' + word)
        last = [problem, {
          'raw_tags': raw_tags, 
          'tags': tags, 
          'difficulty': 'n/a', 
          'comments': ''
        }]
      elif line.startswith('  - difficulty: '): 
        last[1]['difficulty'] = line[16:]
      elif line.startswith('  - '): 
        comment = line[4:]
        if last[1]['comments'] != '': 
          last[1]['comments'] += '; '
        last[1]['comments'] += comment
    if last[0] != None: 
      for tag in last[1]['tags']: 
        if ':' not in tag: 
          index[tag]['problems'].append(last)
        else: 
          [supertag, subtag] = tag.split(':')
          index[supertag]['subtags'][subtag]['problems'].append(last)
  return index
  
def main(): 
  write(read())

if __name__ == '__main__': 
  main()