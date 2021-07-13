
void morphStrings() {
  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if ( !(tempString[j] == timePhrase[j]) ) { // if the chars doesn't match...
      tempString[j] = tempString[j] + 1;
      // rollover
      if (tempString[j] > 'Z') { // that's the last ASCII char!
        tempString[j] = ' '; // first ASCII char
      }
    }
    //Serial.println(tempString);
  }
}

void morphStringsSkip() {

  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if (j == digitSkip) { // skipping
      tempString[j] = timePhrase[j]; // just set it, no "morph"
    }
    else {
      if ( !(tempString[j] == timePhrase[j]) ) { // if the chars doesn't match...
        tempString[j] = tempString[j] + 1;
        // rollover
        if (tempString[j] > 'Z') { // that's the last ASCII char!
          tempString[j] = ' '; // first ASCII char
        }
      }
      //Serial.println(tempString);
    }
  }
}


// we have to swap digits on the last matrix driver for reasons unknown
void setChars() {
  // set every digit to the buffer
  for (uint8_t i = 0; i < NUMCHARS; i++) {
    alpha[i / 4].writeDigitAscii(i % 4, tempString[i]);
  }
}

void writeDisplays() {
  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].writeDisplay();
  }
}

void displayAllChars() {
  for (uint8_t i = '!'; i <= '~'; i++) {
    for (uint8_t j = 0; j < NUMCHARS; j++) {
      uint8_t l = i + j;
      // create blanks when characters go past '~'
      if (l >= '~') l = ' ';
      alpha[j / 4].writeDigitAscii(j % 4, l);
    }
    writeDisplays();
    delay(10);
  }
}

// print time to serial
void printTheTime(DateTime theTimeP) {
  Serial.print(theTimeP.year(), DEC);
  Serial.print('/');
  Serial.print(theTimeP.month(), DEC);
  Serial.print('/');
  Serial.print(theTimeP.day(), DEC);
  Serial.print(' ');
  Serial.print(theTimeP.hour(), DEC);
  Serial.print(':');
  Serial.print(theTimeP.minute(), DEC);
  Serial.print(':');
  Serial.print(theTimeP.second(), DEC);
  Serial.println();
}
