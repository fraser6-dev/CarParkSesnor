# 🚗 Parking Sensor with ESP32

A comprehensive IoT solution for detecting the presence of a car in a parking spot using an ESP32, ultrasonic sensor, and a DHT11 sensor to monitor environmental conditions.

![Photo of the setup showing ESP32 with connected sensors](path_to_image.jpg)   

## 🛠 How it Works

1. **Distance Measurement**: An ultrasonic sensor measures the distance to the nearest object. If this distance is less than 30cm, it is assumed a car is present.
2. **Environment Monitoring**: A DHT11 sensor provides temperature and humidity readings.
3. **ESP32**: This microcontroller fetches the distance and environmental data, processes it, and sends it to the web server. It also uses an RGB LED to indicate the parking spot status: Red means occupied and Green means free.
4. **Web Server**: A Node.js server receives the data from the ESP32 and serves a webpage displaying the parking spot status and environmental conditions.

## 📦 Dependencies

### Hardware

- ESP32
- Ultrasonic Sensor (HC-SR04)
- DHT11 Sensor for Temperature and Humidity
- RGB LED (Red & Green)

### Software

- Arduino IDE with ESP32 board support
- Node.js
- NPM Packages:
    - `express`
    - `arest`
    - `path`

## 🚀 Setup

### ESP32

1. Connect the ultrasonic sensor's trigger pin to pin 12 and echo pin to pin 14 of the ESP32.
2. Connect the DHT11 sensor's data pin to pin 13 of the ESP32.
3. Connect the RGB LED with the Red LED to pin 2 and Green LED to pin 4 of the ESP32.
4. Load the provided `parking_sensor.ino` code into Arduino IDE.
5. Update the WiFi credentials in the code.
6. Upload the code to the ESP32.

### Node.js Server

1. Navigate to the server directory.
2. Install required packages with `npm install express arest path`.
3. Start the server with `node server.js`.
4. Open a browser and navigate to `http://localhost:3000`.

## 📖 Usage

After setting up, the web interface will display the parking spot status and the current temperature and humidity. The status will be:

- **PARKING SPOT TAKEN**: Displayed in red when a car is detected in the parking spot.
- **PARKING SPOT FREE**: Displayed in green when the parking spot is free.
- **No data from ESP32**: Displayed in grey if there's a connection issue or the ESP32 goes offline.

## 📚 Citations

1. [ESP32 Official Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
2. [Express.js Documentation](https://expressjs.com/)
3. [aREST Documentation](https://arest.io/)
4. [DHT Sensor Library for ESPx](https://github.com/beegee-tokyo/DHTesp)
