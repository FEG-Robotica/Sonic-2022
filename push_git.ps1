#
# File:   push_git.ps1
# Author: Gian
#
# Created on 14 de Maio de 2023, 16:08
#
# Para adicionar o repositorio, copie as linhas abaixo!
# Obs: pode ser necessário configurar usuario e email antes de enviar o primeiro código com as linhas abaixo:
#  git config --global user.email "you@example.com"
#  git config --global user.name "Your Name"
#
# echo "# SONIC-HIRO" >> README.md
# git init
# git add README.md
# git commit -m "first commit"
# git branch -M main
# git remote add origin https://github.com/FEG-Robotica/SONIC-HIRO.git
# git push -u origin main
# A linha abaixo executa esse arquivo de script para arquivos serem enviados automaticamente ao GIT
# powershell -executionpolicy bypass -File .\push_git.ps1
git init
git add -A
# Antes de executar o script, editar a linha abaixo com qual modificação foram enviados os arquivos
git commit -m 'update gitignore'
git push
# git push --all origin master