#!/bin/bash


#Record Audio on phone...

#To get the M4A from the phone
adb pull /sdcard/EasyVoiceRecorder/LiamVoiceRecording.m4a /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.m4a

#To convert M4A to MP3
ffmpeg -y -i /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.m4a -acodec libmp3lame -q:a 2 /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.mp3

#Retrieve Audio and translate it with Whisper
whisper /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.mp3 --model medium > /home/lilultime/Cpp_Project/src/MP4Transfer/file.txt

#Use the text to question ChatGPT
python3 /home/lilultime/Cpp_Project/src/ChatGPTLink/makeRequest.py /home/lilultime/Cpp_Project/src/MP4Transfer/file.txt > /home/lilultime/Cpp_Project/src/MP4Transfer/Finalfile.txt

#Open two servers on the computer on port 8080 and 8081
./../CustomHTTPserver/server_linux 8080 8081







