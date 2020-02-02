cat /etc/passwd | sed '/#/d' | sed 's/[:].*//' | awk 'NR%2==0' | rev | sort -r | awk '{if(NR>='$FT_LINE1' && NR<='$FT_LINE2'){print}}' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
