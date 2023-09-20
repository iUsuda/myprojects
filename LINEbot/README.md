# LINEbot
個人のLINEにメッセージを送るbot<br>

### 基本思想と内部処理
LINE messagingAPIは200通/月/アカウントの制限がある。。。じゃあアカウントを増やせばいいじゃないか!!!<br>
- SpreadSheetでbotのアクセストークンと月毎の送信数を管理
- 15分ごとに自動的に使用するbotを更新
- pythonでスプレッドシートからbotのアクセストークン、ユーザーIDを取得して送信

**!注意!** 15分に50件を超えるようなアクセスがあると送信できなくなる可能性があります!

## 準備
### python関連の準備
- Python
  - Python公式サイト[ダウンロードページ](https://www.python.org/downloads/)からダウンロード
- ライブラリ関連
  - line-bot-sdk
  - gspread
  - oauth2client 

  - ライブラリのインストールは以下の通り(xxxはライブラリ名)
```
pip install xxx
```
- SendLINE.pyをダウンロードし、任意のフォルダに置く。Dicordで送信した"linebot.json"を同じフォルダに置く

### LINE関連の準備
1. Discordで送信したQRコードから"通知bot_G1~Gn"を友達追加(nは様子を見て増やします)
2. 通知bot_G1に登録したいユーザー名を送信すると自動でユーザー登録されます。(アルファベットを推奨)※G2以降は送信の必要無し<br>
   ユーザー名を変更したい場合は連絡してください。

ここまで終わったら準備完了!!!ようやく使えます!!!

## 使い方
構文
```
python SendLINE.py -user [ユーザー名] -text [テキスト]
```
オプションの順番は入れ替え可能
- -user　登録したユーザー名を入力
- -text　送信するメッセージを入力

例文
```
python SendLINE.py -user subaru -text あじまるあじまる
```
```
python SendLINE.py -text あじまるあじまる -user subaru
```