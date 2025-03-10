# ESP32 LED Test Setup for ESP32 Wroom DevKit

This repository is an example setup for getting the **ESP32 Wroom DevKit** working with **PlatformIO**. While this repository includes example files, the **real tutorial is in this README**, which guides you through setting up your own ESP32 from scratch.

---

## 🚀 **Introduction**
If you have an **AZDelivery ESP32 Wroom DevKit** and want to:
- Make sure your **ESP-32** is functional
- Set it up with **PlatformIO** on **VS Code**
- Flash a **LED blink test**
- Test **Wi-Fi connectivity**

Then follow the following steps.

---

### **Checking If Your ESP32 is Functional (macOS)**  

Before uploading code, it's important to verify that your Mac recognizes the ESP32.

#### ** Step 1: Check if Your ESP32 is Detected**  
1. Connect your **ESP32** to your **Mac via USB**.  
2. Open the **Terminal** and type:  
   ```sh
   ls /dev/cu.*
   ```
3. If your ESP32 is connected, you should see something like:  
   ```
   /dev/cu.Bluetooth-Incoming-Port  /dev/cu.usbserial-0001
   ```
   The ESP32 is likely `cu.usbserial-0001`, but the exact name may vary.

#### **🛠️ Step 2: Install USB Drivers (If Needed)**  
If you **don’t see** a `/dev/cu.usbserial-XXXX` port, you may need to install drivers:  
- If your ESP32 uses a **CP2102 USB-to-serial chip**, install the **[Silicon Labs CP210x driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)**.  
- If it uses a **CH340 chip**, install the **[CH340 driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)**.  

After installation, **reconnect the ESP32** and try `ls /dev/cu.*` again.

#### **📝 Step 3: Check Serial Communication**  
To ensure your ESP32 can communicate:  
1. Open **VS Code** and go to **PlatformIO > Serial Monitor**  
   - Or run in Terminal:  
     ```sh
     pio device monitor
     ```
2. If your ESP32 is detected, you should see log messages or output from your ESP32 program.

✅ If you see output, **your ESP32 is functional and ready to use!** 🚀

---

## 🛠️ **Step 1: Install Prerequisites**
### Install **VS Code** and **PlatformIO**
1. Download **[Visual Studio Code](https://code.visualstudio.com/)**.
2. Open VS Code and go to **Extensions** (`Ctrl+Shift+X` or `Cmd+Shift+X` on Mac).
3. Search for **PlatformIO IDE** and install it.
4. Restart VS Code.

---

## 🏗️ **Step 2: Create a New PlatformIO Project**
1. Open **VS Code**.
2. Click on **PlatformIO Home** (🔌 icon in the left sidebar).
3. Click **New Project** and configure:
   - **Board**: `ESP32 Dev Module`
   - **Framework**: `Arduino`
   - **Project location**: Choose a directory.
4. Click **Finish** and let PlatformIO set up the project.

---

## 💡 **Step 3: Write the LED Blink Test**
1. Inside your PlatformIO project, go to the `src` folder.
2. Open `main.cpp` (or create one if it doesn’t exist).
3. Copy and paste the following **LED Blink Test** code:

```cpp
#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT); // Set GPIO2 as output (built-in LED)
}

void loop() {
  digitalWrite(2, HIGH); // LED ON
  delay(500);             // Wait 500ms
  digitalWrite(2, LOW);  // LED OFF
  delay(500);             // Wait 500ms
}
