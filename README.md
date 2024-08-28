# 🎵 IoT MP3 Player with Arduino Uno 🎶

Welcome to my latest IoT project! I'm excited to share a modern twist on the classic MP3 player that combines music, technology, and creativity in one compact device.

## 🚀 Project Overview

This IoT MP3 player is designed to randomly select and play songs from your music collection stored on an SD card. It delivers high-quality audio through 8Ω speakers and displays detailed song information on an OLED screen for a complete listening experience.

### Key Features

- **Random Song Selection**: Automatically plays a random song from your SD card library.
- **High-Quality Audio Output**: Uses a DFPlayer Mini to provide seamless playback through 8Ω speakers.
- **OLED Screen Display**: Shows essential song information like the artist, album, year, and even lyrics.
- **Expandable**: Designed with future enhancements in mind, such as LED visualizations and additional control buttons.

## 🛠 Components Used

- **Arduino Uno**: The core microcontroller handling the inputs, outputs, and overall logic.
- **OLED Screen**: Provides a crisp display for song details and visuals.
- **DFPlayer Mini**: A compact module that handles MP3 playback from the SD card.
- **8Ω Speakers**: Delivers clear and high-quality audio.
- **SD Card**: Stores your MP3 files, enabling an extensive music library.

## 📦 Getting Started

Follow these steps to set up your own IoT MP3 Player:

### Prerequisites

- Arduino IDE installed on your computer
- Basic knowledge of Arduino programming and circuit design
- An Arduino Uno, DFPlayer Mini, OLED screen, 8Ω speakers, SD card, and connecting wires

### Installation

1. **Clone the repository**:

2. **Open the Arduino IDE** and load the `.ino` file from the cloned repository.

3. **Install necessary libraries**:
   - [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) for the OLED display
   - [DFPlayer Mini Mp3](https://github.com/DFRobot/DFPlayer-Mini-mp3) for the audio playback

   You can install these libraries via the Arduino Library Manager:

   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - Search for each library and click **Install**.

4. **Assemble the hardware**. Ensure all connections are secure.

5. **Upload the code** to your Arduino Uno.

6. **Insert the SD card** with your MP3 files into the DFPlayer Mini.

7. **Power on your device** and enjoy your custom IoT MP3 player!

## 🔧 How It Works

1. **Initialization**: On startup, the Arduino initializes the DFPlayer Mini and the OLED display.
2. **Random Song Selection**: The Arduino selects a random track from the SD card.
3. **Playback and Display**: The selected song is played through the speakers, and the OLED screen shows song details such as artist, album, year, and lyrics.

## 🎨 Future Enhancements

There are numerous potential upgrades for this project:
- **LED Matrix Visualizations**: Sync music playback with dynamic LED displays.
- **Button Controls**: Add buttons to allow manual song selection and playback control.
- **Bluetooth Connectivity**: Stream music directly from your phone or other devices.


## 📫 Contact

If you have any questions or would like to collaborate, feel free to reach out!

- **LinkedIn**: [Stefanos Ntouvlis](https://www.linkedin.com/in/stefanosntouvlis/)

## 🙌 Acknowledgments

Special thanks to the open-source community for the libraries and resources that made this project possible!
