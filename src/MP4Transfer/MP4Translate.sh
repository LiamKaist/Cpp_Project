#!/bin/bash


#Record Audio

adb pull /sdcard/EasyVoiceRecorder/LiamVoiceRecording.m4a /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.m4a
ffmpeg -y -i /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.m4a -acodec libmp3lame -q:a 2 /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.mp3
#Retrieve Audio and translate it with Whisper

#Print text on a new terminal 


#whisper /home/lilultime/Cpp_Project/src/MP4Transfer/ReceivingEnd.mp3 --model medium > file.txt | cat file.txt | (read string; python3 /home/lilultime/OpenAIProject/src/makeRequest.py "$string") > Finalfile.txt

whisper /home/lilultime/Cpp_Project/src/MP4Transfer/MyPhoneFile/LiamVoiceRecording.mp3 --model medium > /home/lilultime/Cpp_Project/src/MP4Transfer/file.txt 

python3 /home/lilultime/OpenAIProject/src/makeRequest.py /home/lilultime/Cpp_Project/src/MP4Transfer/file.txt > /home/lilultime/Cpp_Project/src/MP4Transfer/Finalfile.txt
#whisper /home/lilultime/Cpp_Project/src/MP4Transfer/ReceivingEnd.mp3 --model medium > file.txt | (read string; python3 /home/lilultime/OpenAIProject/src/makeRequest.py "$string") > Finalfile.txt
#Use the text to question ChatGPT



#To get the MP3 from the phone

#Need to convert M4A to MP3



