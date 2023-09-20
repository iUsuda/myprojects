import os
import sys
from linebot import LineBotApi
from linebot.models import TextSendMessage
from linebot.exceptions import LineBotApiError
from linebot import LineBotSdkDeprecatedIn30
import warnings
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import json

#ignore linebot-warn
#line-bot-sdk v3の記法を理解しきれないため泣く泣く追加。
warnings.filterwarnings("ignore", category=LineBotSdkDeprecatedIn30)

#check json file
json_path = 'linebot.json'#jsonファイルのパスを記述
if not os.path.isfile(json_path):
  print('ERROR: Failed Find File[linebot.json]')
  sys.exit(1)

#get argument
user = ''
token = ''
text = 'テストメッセージ'#デフォルトメッセージ
for i in range(len(sys.argv)):
  arg = sys.argv[i]
  if arg[0] != '-':
    continue
  elif arg == '-text':
    text = sys.argv[i+1]
  elif arg == '-user':
    user = sys.argv[i+1]
  else:
    print('ERROR: Command['+arg+'] is not defind')
    print('Usage: python SendLINE.py -user [username] -text [message]')
    sys.exit(1)
if user == '':
  print('ERROR: Option -user is required')
  print('Usage: python SendLINE.py -user [username] -text [message]')
  sys.exit(1)

#open spreadsheet
scope = ['https://spreadsheets.google.com/feeds','https://www.googleapis.com/auth/drive']
credentials = ServiceAccountCredentials.from_json_keyfile_name(json_path, scope)
gc = gspread.authorize(credentials)
with open(json_path) as f:
  js = json.load(f)
wb = gc.open_by_key(js['spreadsheet_id'])

#get token
ws_main = wb.get_worksheet_by_id(494460932)#書き換えない
list_main = ws_main.get_all_values()
channel_access_token = list_main[0][2]

#get user
ws_user = wb.get_worksheet_by_id(2019719615)#書き換えない
list_user = ws_user.get_all_values()
user_id = ''
for i in range(len(list_user)):
  if user == list_user[i][0]:
    user_id = list_user[i][1]
    break
if user_id == '':
  print('ERROR: User['+user+'] is not registered')
  print('--User List--')
  for i in range(len(list_user)):
    print(list_user[i][0])

#send message
line_bot_api = LineBotApi(channel_access_token)
try:
    line_bot_api.push_message(user_id, TextSendMessage(text=text))
except LineBotApiError as e:
  print(e.message)
  sys.exit(1)

#update spreadsheet
sendcount = int(list_main[0][1])
sendcount += 1
ws_main.update_cell(1,2,sendcount)
