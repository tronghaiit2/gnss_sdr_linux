# BK_GPS_Monitoring

Installation Guide

## Step 1: Install the Operating System

Download the Raspberry Pi Imager software to flash the Debian 64-bit operating system for Raspberry Pi 4:

- [Download Raspberry Pi Imager](https://www.raspberrypi.com/software/)

## Step 2: Set Up the Environment

Run the "install.sh" file to set up the environment for Raspberry Pi 4.

## Step 3: Launch GNSS_SDR

Connect the RTL-SDR 2832U front-end before testing GNSS_SDR.

To test the GNSS_SDR module, perform the following:

- 'cd bundle'
- Run 'assets/bin/gnss-sdr --config_file=assets/conf/test-gnss-sdr_GPS_L1_rtlsdr_realtime.conf'
- Open an additional Terminal in 'bundle'
- Run './tmp/recv' to receive data from GNSS_SDR for checking the message queue
- If there is data exchange, run the "clear_cache.sh" file.

## Step 4: Run the Program

Run the "BK_GPS_Monitoring" file to execute the program.

## Note: Handling Program Errors

Run the "clear_cache.sh" file to reset the GNSS_SDR module.
"clear_cache.sh" is used to clean up files generated during the GNSS_SDR execution.