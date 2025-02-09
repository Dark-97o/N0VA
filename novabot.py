#  PROJECT NOVA 2024, University of Engineeering and Management, Jaipur
#  Department of Computer Science and Engineering , Artifical Intelligence and Machine Learning , Batch 2023-2027 
#  Made By Subhranil Baul - Assisted by Abhishek Kumar , Manas Shit


import speech_recognition as sr   # voice recognition library
import random                     # to choose random words from list
import pyttsx3                    # offline Text to Speech
import webbrowser                 # to open and perform web tasks
import serial                     # for serial communication
import pywhatkit                  # for more web automation

robot_name = 'nova'

hi_words_u = ['hi', 'hello', 'namaskar']
bye_words_u = ['bye', 'tata', 'alvida']
hi_words = ['hi there', 'hello there', 'whats up boss', 'namaskar']
bye_words = ['bye bye', 'bye see you soon', 'sayonara', 'alvida']
r_u_there = ['are you there', 'you there']
jokes = ['What do kids play when their mom is using the phone? Bored games','Why are snails slow? Because they are carrying a house on their back','What’s the smartest insect? A spelling bee!','What does a storm cloud wear under his raincoat? Thunderwear','What is fast, loud and crunchy? A rocket chip','How does the ocean say hi? It waves!','What do you call a couple of chimpanzees sharing an Amazon account? PRIME-mates','Why did the teddy bear say no to dessert? Because she was stuffed']

#  Intializing the Imported Libraries
engine = pyttsx3.init()                    # Text to speech engine
voices = engine.getProperty('voices')      # Check library for voices
engine.setProperty('voice', voices[1].id)  # 0-Male\1-Female
engine.setProperty('rate', 170)            # Voice rate 
listener = sr.Recognizer()                 # Speech recognition

# Check USB port , connect adruino board to correct COM port to connect to physical body
try:
    port = serial.Serial("COM5",9600)
    print("Phycial Body Status: Connected")
except:
    print("Physical Body Status: Disconnected")

def listen():
	try:
		with sr.Microphone() as source:                         # Microphone Access
			print("<<=TALK=>>")
			voice = listener.listen(source)                     # Microphone Listener
			command = listener.recognize_google(voice).lower()  # Google API
			command = command.lower()                          
			print(command)

			if (command.split(' ')[0] == robot_name):
				print("<<=REPLYING=>>")
				process(command)                 # call process funtion to take action
	except:
		pass

def process(words):
	""" process what user says and take actions """
	print(words) # Check for commands Recieved

	word_list = words.split(' ')[1:]   # Split the name and command word

	if word_list[0] == 'play':
		# Youtube
		talk("Okay boss, playing")
		extension = ' '.join(word_list[1:])                   
		port.write(b'u')
		pywhatkit.playonyt(extension)   
		port.write(b'l')          
		return

	elif word_list[0] == 'search':
		# Google Search
		port.write(b'u')
		talk("Okay boss, searching")
		port.write(b'l')
		extension = ' '.join(word_list[1:])
		pywhatkit.search(extension)
		return

	elif word_list[0] == 'dance':
		port.write(b'd')
		talk("Under the sky so wide and free, We chase the dreams we're meant to be. Through every storm and every mile, We carry hope with every smile. Together we rise, you and me!")

	elif word_list[0] == 'help':
		port.write(b'u')
		port.write(b'i')
		talk("Messaging emergency contacts about your situation")
		pywhatkit.sendwhatmsg_instantly("+917004708062", "This is an automated message by Nova,Subhranil has requested emergency help as soon as possible", 15, True, 4)

	elif word_list[0] == 'details':
		port.write(b'u')
		port.write(b'i')
		port.write(b'i')
		talk("Hello I'm Nova, your energetic and helpful companion, designed by the brilliant minds of Team Sankalp! Im just 1 day old, but dont let my age fool you, i have got all the skills to keep things exciting and fun")
		port.write(b'i')
		port.write(b'u')
		port.write(b'i')
		port.write(b'h')
		port.write(b'l')
		talk("Here is what i can do. Say a friendly hi and wave you off with a bye. Help you out with searches when you're curious. Crack jokes that will make you giggle. Play some tunes to brighten your day. Open up applications and assist with tasks. Oh, and if you are looking for action, I can punch, smash, and throw an uppercut. You think i m not energetic enough, i can even do exercise. ")

	if word_list[0] == 'introduce':
		port.write(b'l')
		port.write(b'h')
		talk("Hello, I am Nova your personal companion, here to assist you on your desktop adventures")

	elif word_list[0] == 'joke':
		port.write(b'h')
		talk('Okay boss, here is a joke to enlighten your mood')
		port.write(b'u')
		talk(random.choice(jokes))
  
	elif word_list[0] == 'love':
		talk('I cant process love, but i do love you , sparkle')
		port.write(b'l')
  
	elif word_list[0] == 'exercise':
		port.write(b'w')
		talk('Who took my dumbells')
  
	if (word_list[0] == 'get') and (word_list[1] == 'info'):
		"""if command for getting info"""
		port.write(b'u')
		talk("Okay, I am right on it")
		port.write(b'u')
		extension = ' '.join(word_list[2:])                   
		inf = pywhatkit.info(extension)
		talk(inf)                                              # Result       
		return

	elif word_list[0] == 'open':
		"""if command for opening URLs"""
		port.write(b'l')
		talk("Opening, sir")
		url = f"http://{''.join(word_list[1:])}"
		webbrowser.open(url)
		return
	elif word_list[0] == 'uppercut':
		port.write(b'U')

	elif word_list[0] == 'smash':
		port.write(b's')

	elif word_list[0] == 'punch':
		port.write(b'p')

	for word in word_list:
		if word in hi_words_u:
			""" if user says hi/hello greet him accordingly"""
			port.write(b'h')               
			talk(random.choice(hi_words))

		elif word in bye_words_u:
			""" if user says bye etc"""
			talk(random.choice(bye_words))
			port.write(b'h')


def talk(sentence):
	""" talk / respond to the user """
	engine.say(sentence)
	engine.runAndWait()

while True:
    listen()  # Listens One Time may DisFunction
	
