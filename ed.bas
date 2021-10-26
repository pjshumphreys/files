10 print "(w)rite, (r)ead or (d)elete file?"
20 open 1,0
30 get#1,a$
40 if a$="w" then goto 80
50 if a$="r" then goto 240
60 if a$="d" then goto 350
70 goto 30
80 print "filename to write to? ";
90 input#1,a$
100 open 8,8,15,"i"
110 close 8
120 open 8,8,8,a$+",w"
130 if st>1 then goto 420
140 print
150 print "enter lines now."
160 print "the first character is ignored."
170 print "enter empty string to finish."
180 input#1,a$
190 print
200 if a$="" then goto 330
210 b$=mid$(a$,1)
220 print#8,b$
230 goto 180
240 print "filename to read from? ";
250 input#1,a$
260 print
270 open 8,8,8,a$+",r"
280 a$=""
290 input#8,a$
300 print a$
310 if st>1 then goto 330
320 goto 290
330 close 8
340 end
350 print "filename to delete? ";
360 input#1,a$
370 open 8,8,15,"i"
380 close 8
390 open 8,8,15,"s:"+a$
400 close 8
410 end
420 print "could not open file"