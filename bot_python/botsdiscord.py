import os
import discord
from discord.ext import commands
from dotenv import load_dotenv
import logging


load_dotenv(dotenv_path="config")

logger = logging.getLogger('discord')
logger.setLevel(logging.DEBUG)
handler = logging.FileHandler(filename='discord.log', encoding='utf-8', mode='w')
handler.setFormatter(logging.Formatter('%(asctime)s:%(levelname)s:%(name)s: %(message)s'))
logger.addHandler(handler)



default_intents = discord.Intents.default()
default_intents.members = True

class BotPoo(commands.Bot):
    def __init__(self):
        super().__init__(command_prefix="!")

    async def on_ready(self):
        print(f"{self.user.display_name} est connecté au serveur.")

Bot_Poo = BotPoo()


@Bot_Poo.event
async def on_member_join(member):
    channel = Bot_Poo.get_channel(963708895749099542)
    await channel.send(f"Bienvenue a {member.mention} sur le serveur !")

@Bot_Poo.command(name="del")
async def delete(ctx, number: int):
    messages = await ctx.channel.history(limit=number + 1).flatten()
    for each_message in messages:
        await each_message.delete()

@Bot_Poo.command(name="ping")
async def on_message(message):
    await message.channel.send("Pong")

@Bot_Poo.command(name="pong")
async def on_message(message):
    await message.channel.send("Ping")

@Bot_Poo.command(name="esiea")
async def on_message(message):
    await message.channel.send("https://www.esiea.fr/")

@Bot_Poo.command(name="moodle")
async def on_message(message):
    await message.channel.send("https://learning.esiea.fr/login/index.php")

Bot_Poo.run(os.getenv("TOKEN"))