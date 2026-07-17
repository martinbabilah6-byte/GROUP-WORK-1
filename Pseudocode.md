BEGIN
   PRINT "Circuit Breaker and Fuse Selection System"
   INPUT numberOfCircuits

   IF numberOfCircuits <= 0 THEN
       PRINT "Invalid number of circuits"
       EXIT
   ENDIF

   OPEN report file "protection_report.txt"

   FOR i = 1 TO numberOfCircuits DO
       REPEAT
           INPUT circuitName
           INPUT supplyVoltage
           INPUT totalPower
       UNTIL supplyVoltage > 0 AND totalPower > 0

       COMPUTE loadCurrent = totalPower / supplyVoltage
       COMPUTE designCurrent = loadCurrent * 1.25

       SET recommendedRating = -1
       FOR each rating in {6,10,16,20,25,32,40,63} DO
           IF designCurrent <= rating THEN
               recommendedRating = rating
               protectionStatus = "Device selected"
               BREAK
           ENDIF
       ENDFOR

       IF recommendedRating = -1 THEN
           protectionStatus = "No standard rating available"
       ENDIF

       PRINT circuitName, loadCurrent, designCurrent, recommendedRating, protectionStatus
       WRITE same details to report file
   ENDFOR

   CLOSE report file
   PRINT "Report saved to protection_report.txt"
END

