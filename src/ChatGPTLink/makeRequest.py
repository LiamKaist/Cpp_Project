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
        {"role": "system", "content": "You can only answer with numbers 100, 200 or 300"},
        {"role": "user", "content":  "Tell me precisely how many millilitres of water this person wants (either 100, 200 or 300), if they want anything other than 100,200 or 300 mL, just answer 300: " + gatheredText}
    ]
)

fd.close()
JSON=response["choices"]

print(JSON[0]["message"]["content"])





