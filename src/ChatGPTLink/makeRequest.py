#!/usr/bin/python3

import sys
import os
import openai
import json


#Access text provided by the command line
filePath= sys.argv[1]

openai.api_key = "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"  #This key was obtained via OpenAI's API website, I am being charged money for each token my requests consume
fd=open(filePath,'r')
gatheredText=fd.read()

#inputText= input("Ask a question, please\n") if you want to input your own text

response=openai.ChatCompletion.create(
  model="gpt-3.5-turbo",
  messages=[
        {"role": "system", "content": "You can only answer with numbers 0, 100, 200 or 300"},
        {"role": "user", "content":  "Tell me precisely how many millilitres of any kind of drink this person wants (either 100, 200 or 300), if they seem thirsty give them 300, if they don't seem too thirsty give them 100. If they specifically say medium, answer 200, if they don't want a drink answer 0: " + gatheredText}
    ]
)

fd.close()
JSON=response["choices"]

print(JSON[0]["message"]["content"])





