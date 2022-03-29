import re
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options

debug = False

def get_comments(name): 
  comments = []
  comment = input(f'enter comment for "{name}": ')
  while comment != "": 
    comments.append(comment)
    comment = input(f'enter comment for "{name}": ')
  return comments

def add_list_entry(platform, id, name, link, tags, difficulty, comments): 
  if debug: 
    print(f'- [{platform} {id} - {name}]({link}) - {tags}')
    if difficulty != "": 
      print(f'  - difficulty: {difficulty}')
    for comment in comments: 
      print(f'  - {comment}')
  else: 
    with open('../list.md', 'a') as f: 
      f.write(f'- [{platform} {id} - {name}]({link}) - {tags}\n')
      if difficulty != "": 
        f.write(f'  - difficulty: {difficulty}\n')
      for comment in comments: 
        f.write(f'  - {comment}\n')

def get_codeforces_problem_link(id): 
  if id[-1].isdigit(): 
    return f'https://codeforces.com/problemset/problem/{id[:-2]}/{id[-2:].upper()}'
  else:
    return f'https://codeforces.com/problemset/problem/{id[:-1]}/{id[-1].upper()}'

# todo: tags & difficulty
def get_codeforces_problem_info(id, cftags, driver): 
  driver.get(get_codeforces_problem_link(id))
  elems = driver.find_elements(By.CLASS_NAME, 'title')
  name = elems[0].get_attribute('innerHTML').lower()
  name = name[name.index(' ') + 1:]
  elems = driver.find_elements(By.CLASS_NAME, 'tag-box')
  raw_tags = []
  difficulty = ''
  for elem in elems: 
    tag = elem.get_attribute('innerHTML').strip()
    if re.match(r'\*[12389][0-9]?00', tag): 
      difficulty = tag[1:]
    else: 
      tag = cftags[tag]
      if tag != 'ignore': 
        raw_tags.append(tag)
  return [name, raw_tags, difficulty]

def add_codeforces_list_entry(id, cftags, driver): 
  link = get_codeforces_problem_link(id)
  [name, raw_tags, difficulty] = get_codeforces_problem_info(id, cftags, driver)
  tags = ''
  raw_tags = sorted(raw_tags)
  for i in range(len(raw_tags)): 
    tag = raw_tags[i]
    if ':' in tag: 
      if i == 0: 
        tags += f'{tag.split(":")[0]}: {tag.split(":")[1]}'
      elif tag.split(":")[0] not in raw_tags: 
        tags += f'; {tag.split(":")[0]}: {tag.split(":")[1]}'
      elif raw_tags[i - 1] == tag.split(':')[0]: 
        tags += f': {tag.split(":")[1]}'
      else: 
        tags += f', {tag.split(":")[1]}'
    else: 
      if i != 0: 
        tags += f'; {tag}'
      else:
        tags += tag
  comments = get_comments(id)
  add_list_entry('codeforces', id, name, link, tags, difficulty, comments)

def main(): 
  options = Options()
  options.binary_location = r'D:\Program Files\Google\Chrome\Application\chrome.exe'
  options.add_argument('--headless')
  options.add_argument('--log-level=3')
  options.add_experimental_option('excludeSwitches', ['enable-logging'])
  driver = webdriver.Chrome(options = options)

  cftags = {}
  with open('tags/cf.tags') as f: 
    for line in f.readlines(): 
      line = line.rstrip()
      if '=' in line: 
        cftags[line.split('=')[0]] = line.split('=')[1]
      else: 
        cftags[line] = line

  for filename in os.listdir('../temp'):
    f = os.path.join('../temp', filename)
    if os.path.isfile(f):
      if re.match(r'[1-9][0-9]*[a-zA-Z][1-9]?(_[1-9][0-9]?)?', filename): 
        get_codeforces_problem_info(filename.split('.')[0], cftags, driver)
        add_codeforces_list_entry(filename.split('.')[0], cftags, driver)
        if not debug: 
          os.rename(os.path.join('../temp', filename), os.path.join('../cf', filename))
        print(f'moved "{os.path.join("temp", filename)}" to "{os.path.join("cf", filename)}".')
      else: 
        platform = input(f'enter platform for "{filename}": ')
        name = input(f'enter problem name for "{filename}": ')
        link = input(f'enter problem link for "{filename}": ')
        tags = input(f'enter tags for "{filename}": ')
        difficulty = input(f'enter difficulty for "{filename}": ')
        comments = get_comments(filename)
        add_list_entry(platform, name, filename.split('.')[0], link, tags, difficulty, comments)
      

if __name__ == '__main__': 
  main()
  exec(open('list2index.py').read())