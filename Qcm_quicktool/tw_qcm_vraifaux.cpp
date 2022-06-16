target=tw01_generalites tw01_xml tw02_html_debut tw02_images

%%Le source de cet exercice a été créé à l'aide de Quicktool
%%Le type de l'exercice est TRUEFALSE.
%%Exercice de qcm: 4 questions aleatoires par page, tirees depuis un fichier de donnees
%%Reponses: Vrai ou Faux. Un peu de personnalisation de la presentation des reponses.
%%ne pas oublier de declarer les fichiers cible tout en haut de ce fichier !

###################
#if defined TARGET_tw01_generalites
\title{tw01_generalites}
\text{file=tw01_generalites_data.txt}
#endif
#if defined TARGET_tw01_xml
\title{tw01_xml}
\text{file=tw01_xml_data.txt}
#endif
#if defined TARGET_tw02_html_debut
\title{tw02_html_debut}
\text{file=tw02_html_debut_data.txt}
#endif
#if defined TARGET_tw02_images
\title{tw02_images}
\text{file=tw02_images_data.txt}
#endif


\author{Jocelyn,Druel}
\email{jocelyn.druel@univ-littoral.fr}
\css{<style>
   .question {}
   .reponse {}
   .prompt {}
   .instruction{}
   ol li {list-style:upper-alpha;};.question{margin:0.2%;}; .reponse{margin:0.2%;}
 </style>}
\language{fr}
\computeanswer{no}
\format{html}
\text{notepad=slib(utilities/notepad Notepad,small)}
\text{instruction=asis()}
\text{instruction2=asis()}
\text{choice=}
\text{common=}
\text{audio_file=no}
\text{reading_file=no}
\text{image_file=no}
\text{video_file=no}
\text{alea=yes}
\text{size=}
\text{partialscore=split}
\text{percent=1}
\text{aucune=aucune de ces possibilités}
\text{format=checkbox}
\text{format0=mark}
\text{specialhelp1=}
\text{specialhelp2=}
\text{specialhelp3=}
\text{specialhelp4=}
\text{helpprompt=}
\text{reaccent=}
\text{paste=yes}
\text{pos_rep=inside}
\text{second_step=yes}
\text{first_step=1}
\text{answer_given=}
\text{try=}
\text{packs=}
\text{player=}
\text{player_option=}
#####################
\text{presentgood=}
\text{file0=randitem(\file)}
\integer{cnt_question= wims(recordcnt \file0)}

################
\text{MAX=1}
\text{N=4}
\text{M=3}
################
\text{option=\format0 iswordof flashcard?show}
\text{ff=\format0 iswordof flashcard ?s;&nbsp;}
\text{autocompletion=\format iswordof case nocase ? autocomplete="off"}
\text{player=wims(replace internal - by in \player)}
\text{specialhelp=\specialhelp1,\specialhelp2,\specialhelp3,\specialhelp4}
\text{helpprompt=\helpprompt = ?++>}
\integer{first_step=\first_step notwordof 0 ? 1}
\text{option_reaccent=\reaccent!=yes ? noreaccent:}
\text{nopaste=\paste issametext no ? slib(utilities/nopaste )}

\text{instruction=\instruction issametext ? wims(getdef instruction in \file0)}
\text{instruction=wims(\instruction)}
\text{instruction2=\instruction2 issametext ? wims(getdef instruction2 in \file0)}
\text{instruction2=wims(\instruction2)}
\text{size=\size issametext ? wims(getdef size in \file0)}
\text{reading_file=\reading_file issametext ? wims(getdef reading_file in \file0)}
\text{reading = wims(record 0 of \reading_file)}
\text{reading=wims(\reading)}
\text{audio_file = \audio_file issametext ? wims(getdef audio_file in \file0)}
\text{audio=\audio_file notsametext and \audio_file notsametext no?
<div class="wimscenter">slib(media/audio \imagedir/\audio_file,\player_option,player=\player)</div>}

\text{image_file=\image_file issametext ? wims(getdef image_file in \file0)}
\text{image=\image_file notsametext and \image_file notsametext no?
wims(makelist <img src="\imagedir/x " alt="" /> for x in \image_file)}

\text{video_file=\video_file issametext ? wims(getdef video_file in \file0)}
\if{\video_file notsametext and \video_file notsametext no}{
  \text{video_file=http notin \video_file ? \imagedir/\video_file}
\text{video=\video_file notsametext ? <div><a target="wims_external" href="\video_file">[video]</a></div>}
}
\text{choix=\choice issametext ? wims(getdef choice in \file0):\choice}

\text{try =\try notwordof 1 2 3 4 5 6 7 8 9 10 ? 1}
\text{size=\format iswordof dragfill clickfill ? \size x 1}
\integer{N = min(\cnt_question,\N)}
\integer{MAX=min(\N*\MAX,\cnt_question)}
\text{battage=\alea issametext yes ? shuffle(\cnt_question) :
wims(makelist x for x = 1 to \cnt_question)}
      \text{option=\option noanalyzeprint}
\matrix{phrase =}
\matrix{explication=}
\text{reponse=}
\text{PRELIMINAIRE=}
\for{ i = 1 to \MAX}{
  \text{texte = wims(record \battage[\i] of \file)}
  \text{texte=wims(\texte)}
  \text{texte = wims(embraced randitem \texte)}
  \text{preliminaire_test=\texte}
  \text{preliminaire_test=row(1,\preliminaire_test)}
  \text{inst_audio=wims(getopt audio in \preliminaire_test)}
  \text{inst_image=wims(getopt image in \preliminaire_test)}
  \text{inst_title=wims(getopt title in \preliminaire_test)}
  \text{inst_intro=wims(getopt intro in \preliminaire_test)}
  \integer{test_inst=\inst_audio\inst_image\inst_title\inst_intro  notsametext ? 1 : 0}
  \text{rab_inst=}
  \text{rab_inst=\inst_title notsametext ?\rab_inst<div class="wimscenter">\inst_title</div>}
  \text{rab_inst=\inst_intro notsametext ?\rab_inst \inst_intro}
  \text{rab_inst=\inst_image notsametext ? \rab_inst <div class="wimscenter"><img src="\imagedir/\inst_image" alt="" /></div>}
  \if{\inst_audio notsametext }{
     \text{rab_inst1= . isin \inst_audio or \packs= ?
       slib(media/audio \imagedir/\inst_audio,\player_option,player=\player):slib(lang/swac \inst_audio,\packs,player=\player,\player_option)}
     \text{rab_inst=\rab_inst <div class="wimscenter">\rab_inst1[1;1]</div>}
   }
   \text{preliminaire=\test_inst=1 ? \rab_inst:&nbsp;}
  \text{texte=\test_inst=1 ? wims(line 2 to -1 of \texte)}
  \matrix{PRELIMINAIRE=\PRELIMINAIRE
  \preliminaire}
  \integer{cnt_choix= rows(\texte)-1}
  \integer{cnt_choix=(\cnt_choix-1)/2}
  \text{h =randint(1..\cnt_choix)}
  \matrix{phrase=\phrase
  \texte[2*\h;]}
  \text{explication=\i = 1 ? \texte[1;] : \explication;\texte[1;]}  
\text{reponse=\reponse, position(\texte[2*\h+1;],\choix)}
}
\text{reponse=wims(nonempty items \reponse)}

\text{STEP = wims(makelist r x for x = 1 to \MAX)}
\text{U = pari(divrem(\MAX,\N)~)}
\integer{cnt_step = \U[2] !=0 ? \U[1] + 1:\U[1]}
\matrix{STEPS = }
\for{ u = 1 to \cnt_step -1}{
   \matrix{STEPS =\STEPS
wims(makelist r x for x = \N*\u -\N+1 to \N*\u)
   }
}
 \matrix{STEPS = \STEPS
 wims(makelist r x for x = \N*\cnt_step-\N+1 to \MAX)
}
\steps{\STEPS}

\statement{\nopaste
<div class="instruction">\instruction</div> \if{\reading notsametext }{\special{help reading,[à lire]}}
\if{\image notsametext }{\special{help image,[à regarder]}}
\audio\video
\if{\step>1}{
<ol>
\for{ l = 1 to \N*(\step-1)} {
<li>
  \PRELIMINAIRE[\l;] \phrase[\l;]
 </li>
 }
</ol>
}
  \for{ t = 1 to \N}{
  <strong>Question \t:</strong>
  \PRELIMINAIRE[\N*(\step-1) + \t;]
   <div class="question">   
      \phrase[\N*(\step-1) + \t;]   
      <div class="wimscenter">
         \embed{\STEPS[\step;\t] }    
      </div>
    <hr class="style-one">
   </div>
   }
}

\answer{1}{\reponse[1];\choix}{type=radio}
\answer{2}{\reponse[2];\choix}{type=radio}
\answer{3}{\reponse[3];\choix}{type=radio}
\answer{4}{\reponse[4];\choix}{type=radio}
\answer{5}{\reponse[5];\choix}{type=radio}
\answer{6}{\reponse[6];\choix}{type=radio}
\answer{7}{\reponse[7];\choix}{type=radio}
\answer{8}{\reponse[8];\choix}{type=radio}
\answer{9}{\reponse[9];\choix}{type=radio}
\answer{10}{\reponse[10];\choix}{type=radio}
\answer{11}{\reponse[11];\choix}{type=radio}
\answer{12}{\reponse[12];\choix}{type=radio}
\answer{13}{\reponse[13];\choix}{type=radio}
\answer{14}{\reponse[14];\choix}{type=radio}
\answer{15}{\reponse[15];\choix}{type=radio}
\answer{16}{\reponse[16];\choix}{type=radio}
\answer{17}{\reponse[17];\choix}{type=radio}
\answer{18}{\reponse[18];\choix}{type=radio}
\answer{19}{\reponse[19];\choix}{type=radio}
\answer{20}{\reponse[20];\choix}{type=radio}
\feedback {1 <= \MAX and \N*\step >=1 and (\choix[\reponse[1]] issametext \choix[2] or \choix[\reponse[1]] notsametext \reply1)
  and \explication[1;] notsametext }{
<div class="reponse">1 : \explication[1;]</div>}
\feedback {2 <= \MAX and \N*\step >=2 and (\choix[\reponse[2]] issametext \choix[2] or \choix[\reponse[2]] notsametext \reply2)
  and \explication[2;] notsametext }{
<div class="reponse">2 : \explication[2;]</div>}
\feedback {3 <= \MAX and \N*\step >=3 and (\choix[\reponse[3]] issametext \choix[2] or \choix[\reponse[3]] notsametext \reply3)
  and \explication[3;] notsametext }{
<div class="reponse">3 : \explication[3;]</div>}
\feedback {4 <= \MAX and \N*\step >=4 and (\choix[\reponse[4]] issametext \choix[2] or \choix[\reponse[4]] notsametext \reply4)
  and \explication[4;] notsametext }{
<div class="reponse">4 : \explication[4;]</div>}
\feedback {5 <= \MAX and \N*\step >=5 and (\choix[\reponse[5]] issametext \choix[2] or \choix[\reponse[5]] notsametext \reply5)
  and \explication[5;] notsametext }{
<div class="reponse">5 : \explication[5;]</div>}
\feedback {6 <= \MAX and \N*\step >=6 and (\choix[\reponse[6]] issametext \choix[2] or \choix[\reponse[6]] notsametext \reply6)
  and \explication[6;] notsametext }{
<div class="reponse">6 : \explication[6;]</div>}
\feedback {7 <= \MAX and \N*\step >=7 and (\choix[\reponse[7]] issametext \choix[2] or \choix[\reponse[7]] notsametext \reply7)
  and \explication[7;] notsametext }{
<div class="reponse">7 : \explication[7;]</div>}
\feedback {8 <= \MAX and \N*\step >=8 and (\choix[\reponse[8]] issametext \choix[2] or \choix[\reponse[8]] notsametext \reply8)
  and \explication[8;] notsametext }{
<div class="reponse">8 : \explication[8;]</div>}
\feedback {9 <= \MAX and \N*\step >=9 and (\choix[\reponse[9]] issametext \choix[2] or \choix[\reponse[9]] notsametext \reply9)
  and \explication[9;] notsametext }{
<div class="reponse">9 : \explication[9;]</div>}
\feedback {10 <= \MAX and \N*\step >=10 and (\choix[\reponse[10]] issametext \choix[2] or \choix[\reponse[10]] notsametext \reply10)
  and \explication[10;] notsametext }{
<div class="reponse">10 : \explication[10;]</div>}
\feedback {11 <= \MAX and \N*\step >=11 and (\choix[\reponse[11]] issametext \choix[2] or \choix[\reponse[11]] notsametext \reply11)
  and \explication[11;] notsametext }{
<div class="reponse">11 : \explication[11;]</div>}
\feedback {12 <= \MAX and \N*\step >=12 and (\choix[\reponse[12]] issametext \choix[2] or \choix[\reponse[12]] notsametext \reply12)
  and \explication[12;] notsametext }{
<div class="reponse">12 : \explication[12;]</div>}
\feedback {13 <= \MAX and \N*\step >=13 and (\choix[\reponse[13]] issametext \choix[2] or \choix[\reponse[13]] notsametext \reply13)
  and \explication[13;] notsametext }{
<div class="reponse">13 : \explication[13;]</div>}
\feedback {14 <= \MAX and \N*\step >=14 and (\choix[\reponse[14]] issametext \choix[2] or \choix[\reponse[14]] notsametext \reply14)
  and \explication[14;] notsametext }{
<div class="reponse">14 : \explication[14;]</div>}
\feedback {15 <= \MAX and \N*\step >=15 and (\choix[\reponse[15]] issametext \choix[2] or \choix[\reponse[15]] notsametext \reply15)
  and \explication[15;] notsametext }{
<div class="reponse">15 : \explication[15;]</div>}
\feedback {16 <= \MAX and \N*\step >=16 and (\choix[\reponse[16]] issametext \choix[2] or \choix[\reponse[16]] notsametext \reply16)
  and \explication[16;] notsametext }{
<div class="reponse">16 : \explication[16;]</div>}
\feedback {17 <= \MAX and \N*\step >=17 and (\choix[\reponse[17]] issametext \choix[2] or \choix[\reponse[17]] notsametext \reply17)
  and \explication[17;] notsametext }{
<div class="reponse">17 : \explication[17;]</div>}
\feedback {18 <= \MAX and \N*\step >=18 and (\choix[\reponse[18]] issametext \choix[2] or \choix[\reponse[18]] notsametext \reply18)
  and \explication[18;] notsametext }{
<div class="reponse">18 : \explication[18;]</div>}
\feedback {19 <= \MAX and \N*\step >=19 and (\choix[\reponse[19]] issametext \choix[2] or \choix[\reponse[19]] notsametext \reply19)
  and \explication[19;] notsametext }{
<div class="reponse">19 : \explication[19;]</div>}
\feedback {20 <= \MAX and \N*\step >=20 and (\choix[\reponse[20]] issametext \choix[2] or \choix[\reponse[20]] notsametext \reply20)
  and \explication[20;] notsametext }{
<div class="reponse">20 : \explication[20;]</div>}
