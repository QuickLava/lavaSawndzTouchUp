#include "lavaSawndz.h"

namespace lava
{
	// Returns 1 if the specified err message was cut off
	bool printError(int errnoIn)
	{
		std::vector<char> errorMessageBuffer{};
		// I'm currently hardcoding the err buffer to 32, because Visual Studio doesn't have an implementation of strerrorlen_s to properly check the length of the message.
		errorMessageBuffer.resize(32);
		// Get the message and store it in errorMessageBuffer, recording whether the message got cut off
		bool fullMessageGotten = strerror_s(errorMessageBuffer.data(), 32, errno);
		std::cerr << std::string(errorMessageBuffer.data());
		return fullMessageGotten;
	}

	unsigned long countCharInString(const std::string& stringIn, char searchIn)
	{
		unsigned long count = 0;
		for (std::size_t i = 0; i < stringIn.size(); i++)
		{
			count += stringIn[i] == searchIn;
		}
		return count;
	}
	std::size_t findNthInString(const std::string& stringIn, char searchIn, unsigned long n)
	{
		std::size_t result = SIZE_MAX;

		std::size_t stringLength = stringIn.size();
		if (n < stringLength)
		{
			std::size_t index = 0;
			unsigned long count = 0;
			while (index < stringLength && count < n)
			{
				if (stringIn[index] == searchIn)
				{
					count++;
				}
				if (count < n)
				{
					index++;
				}
			}

			if (count == n)
			{
				result = index;
			}

		}
		return result;
	}

	namespace brawl
	{
		namespace sawndz
		{
			bool groupFileInfo::fileIDAcceptable(unsigned long fileIDIn)
			{
				bool result = 0;
				std::size_t i = 0;
				while (!result && i < acceptableFileIDs.size())
				{
					result = acceptableFileIDs[i] == fileIDIn;
					i++;
				}
				return result;
			}
			std::unordered_map<unsigned long, groupFileInfo> fighterIDToGroupInfoMap = {
				{ LCFI_CAPTAIN_FALCON, { 20, {136, 755}}},
				{ LCFI_DEDEDE, {12, {560, 151}}},
				{ LCFI_DIDDY_KONG, {33, {143, 585}}},
				{ LCFI_DONKEY_KONG, {13, {500, 163}}},
				{ LCFI_FALCO, {28, {383, 144}}},
				{ LCFI_FOX, {17, {528, 621}}},
				{ LCFI_GANONDORF, { 29, {583, 296}}},
				{ LCFI_MR_GAME_AND_WATCH, { 27, {461, 526}}},
				{ LCFI_GIGA_BOWSER, { 22, {475, 171}}},
				{ LCFI_IKE, { 39, {617, 710}}},
				{ LCFI_KIRBY, { 16, {161, 457}}},
				{ LCFI_BOWSER, { 22, {484, 180}}},
				{ LCFI_LINK, { 9, {406, 186}}},
				{ LCFI_LUCARIO, { 38, {472, 620}}},
				{ LCFI_LUCAS, { 32, {377, 533}}},
				{ LCFI_LUIGI, { 19, {558, 254}}},
				{ LCFI_MARIO, { 8, {813, 260}}},
				{ LCFI_MARTH, { 26, {713, 537}}},
				{ LCFI_META_KNIGHT, { 11, {683, 486}}},
				{ LCFI_NANA, { 25, {596, 701}}},
				{ LCFI_NESS, { 21, {132, 187}}},
				{ LCFI_PEACH, { 23, {487, 751}}},
				{ LCFI_PIKACHU, { 18, {595, 250}}},
				{ LCFI_OLIMAR, { 31, {687, 395}}},
				{ LCFI_PIT, { 10, {479, 577}}},
				{ LCFI_IVYSAUR, { 37, {301, 446}}},
				{ LCFI_CHARIZARD, { 35, {542, 536}}},
				{ LCFI_POKEMON_TRAINER, { 34, {178, 543}}},
				{ LCFI_SQUIRTLE, { 36, {594, 248}}},
				{ LCFI_POPO, { 25, {339, 469}}},
				{ LCFI_JIGGLYPUFF, { 41, {609, 423}}},
				{ LCFI_ROB, { 40, {574, 720}}},
				{ LCFI_SAMUS, { 14, {255, 80}}},
				{ LCFI_SHEIK, { 24, {735, 442}}},
				{ LCFI_SNAKE, { 44, {261, 629}}},
				{ LCFI_SONIC, { 45, {130, 600}}},
				{ LCFI_ZERO_SUIT_SAMUS, { 14, {754, 630}}},
				{ LCFI_TOON_LINK, { 42, {712, 539}}},
				{ LCFI_WARIO, { 30, {680, 480}}},
				{ LCFI_WOLF, { 43, {378, 470}}},
				{ LCFI_YOSHI, { 15, {689, 573}}},
				{ LCFI_ZELDA, { 24, {481, 253}}},
			};

			std::unordered_map<std::string, std::string> soundEffectNameOverrides =
			{
				// Meta Knight & Pit Overrides
				{"snd_vc_atk01", "snd_vc_Attack01"},
				{"snd_vc_atk02", "snd_vc_Attack02"},
				{"snd_vc_atk03", "snd_vc_Attack03"},
				{"snd_vc_atk04", "snd_vc_Attack04"},
				{"snd_vc_atk05", "snd_vc_Attack05"},
				{"snd_vc_atk06", "snd_vc_Attack06"},
				{"snd_vc_atk07", "snd_vc_Attack07"},
				{"snd_vc_hoshikie", "snd_vc_Damage_hoshikie"},
				{"snd_vc_damage_s", "snd_vc_Damage01"},
				{"snd_vc_damage_l", "snd_vc_Damage02"},
				{"snd_vc_futtobi_l01", "snd_vc_DamageFly01"},
				{"snd_vc_futtobi_l02", "snd_vc_DamageFly02"},
				{"snd_vc_futtobi_l02", "snd_vc_DamageFly02"},
				{"snd_vc_mizu_tobidashi", "snd_vc_SwimUp"},
				{"snd_vc_miss01", "snd_vc_MissFoot01"},
				{"snd_vc_miss02", "snd_vc_MissFoot02"},
				{"snd_vc_fura", "snd_vc_FuraFura"},
				{"snd_vc_otto", "snd_vc_Ottotto"},
				{"snd_vc_nemuru", "snd_vc_FuraSleep"},
				{"snd_vc_gake", "snd_vc_CliffCatch"},
				{"snd_vc_mochiage", "snd_vc_HeavyGet"},
				{"snd_vc_ukemi", "snd_vc_Passive"},
				// Meta Knight & Pit Overrides (Destructive)
				{"snd_vc_atk_hyaku", "snd_vc_001"},
				{"snd_vc_hissatu_n", "snd_vc_002"},
				{"snd_vc_hissatu_ue", "snd_vc_002"},
				{"snd_vc_hissatu_yoko", "snd_vc_003"},
				{"snd_vc_hissatu_shita", "snd_vc_004"},
				{"snd_vc_hissatu_shita01", "snd_vc_004"},
				{"snd_vc_hissatu_shita02", "snd_vc_005"},
				{"snd_vc_kakkuu", "snd_vc_005"},
				{"snd_vc_hissatu_cyo01", "snd_vc_006"},
				{"snd_vc_hissatu_cyo02", "snd_vc_007"},
				{"snd_vc_hissatu_cyo03", "snd_vc_008"},
				{"snd_vc_hissatu_cyo03", "snd_vc_008"},
				{"snd_vc_win04", "snd_vc_009"},
				// Dedede Overrides
				{"snd_se_hammer_Attack_l", "snd_se_Attack_l"},
				{"snd_se_hammer_Attack_ll", "snd_se_Attack_ll"},
				{"snd_se_hammer_Attack_m", "snd_se_Attack_m"},
				{"snd_se_hammer_Attack_s", "snd_se_Attack_s"},
				{"snd_se_hammer_Attack100", "snd_se_Attack100"},
				{"snd_se_hammer_swing_l", "snd_se_swing_l"},
				{"snd_se_hammer_swing_ll", "snd_se_swing_ll"},
				{"snd_se_hammer_swing_m", "snd_se_swing_m"},
				{"snd_se_hammer_swing_s", "snd_se_swing_s"},
				// Dedede Overrides (Destructive)
				{"snd_se_hammer_Attack_earth", "snd_se_024"},
				{"snd_se_hammer_spin_body", "snd_se_025"},
				{"snd_se_hammer_spin_head", "snd_se_026"},
				// Donkey Kong Overrides
				{"snd_se_TCB_perfect", "snd_se_025"},
				// Donkey Kong Overrides (Destructive)
				{"snd_se_Final_Conga_l", "snd_se_026"},
				{"snd_se_Final_Conga_r", "snd_se_027"},
				// Donkey Kong Overrides (Dangerous)
				{"snd_se_Final_Claps", "snd_se_028"},
				// Falco Overrides
				{"snd_vc_Win_Fox", "snd_vc_008"},
				// Fox Overrides
				{"snd_vc_Win_Falco", "snd_vc_005"},
				// Peach Overrides
				{"snd_se_Attack_Binta", "snd_se_005"},
				{"snd_se_Attack_Smash01_Fryingpan", "snd_se_006"},
				{"snd_se_Attack_Smash02_Golfclub", "snd_se_007"},
				{"snd_se_Attack_Smash03_Tennisracket", "snd_se_008"},
			};
			std::string shuckSoundEffectName(std::string nameIn, std::unordered_map<std::string, std::string>::iterator* overrideUsedOut)
			{
				std::string result = "";

				std::size_t underscoreCount = 0;
				for (std::size_t i = 0; i < nameIn.size(); i++)
				{
					underscoreCount += nameIn[i] == '_';
				}

				if (underscoreCount >= 3)
				{
					if (nameIn.find("snd_vc_ouen") == 0)
					{
						result = "snd_vc_ouen";
					}
					else
					{
						result = nameIn.substr(0, findNthInString(nameIn, '_', 2)) + nameIn.substr(findNthInString(nameIn, '_', 3));
						std::unordered_map<std::string, std::string>::iterator findResult = soundEffectNameOverrides.find(result);
						if (findResult != soundEffectNameOverrides.end())
						{
							result = findResult->second;
							if (overrideUsedOut != nullptr)
							{
								*overrideUsedOut = findResult;
							}
						}
						else
						{
							if (overrideUsedOut != nullptr)
							{
								*overrideUsedOut = soundEffectNameOverrides.end();
							}
						}
					}
				}
				result = lava::stringToUpper(result);
				return result;
			}

			/* Brawl Reference */

			brawlReference::brawlReference(unsigned long long valueIn)
			{
				isOffset = bool(valueIn & 0xFFFFFFFF00000000);
				address = valueIn & 0x00000000FFFFFFFF;
			}
			unsigned long brawlReference::getAddress(unsigned long relativeToIn)
			{
				unsigned long result = address;
				if (isOffset)
				{
					if (relativeToIn != ULONG_MAX)
					{
						result += relativeToIn;
					}
				}
				return result;
			}
			std::string brawlReference::getAddressString(unsigned long relativeToIn)
			{
				return lava::numToHexStringWithPadding(getAddress(relativeToIn), 8);
			}
			unsigned long long brawlReference::getHex()
			{
				unsigned long long result = address;
				if (isOffset)
				{
					result |= 0x0100000000000000;
				}
				return result;
			}

			bool brawlReferenceVector::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated() && (addressIn < bodyIn.body.size()))
				{
					std::size_t count = bodyIn.getLong(addressIn);
					refs.resize(count);
					unsigned long cursor = addressIn + 0x04;
					for (std::size_t i = 0; i < count; i++)
					{
						refs[i] = brawlReference(bodyIn.getLLong(cursor));
						cursor += 0x08;
					}
					result = 1;
				}

				return result;
			}
			std::vector<unsigned long> brawlReferenceVector::getHex()
			{
				std::vector<unsigned long> result{};

				result.push_back(refs.size());
				for (std::size_t i = 0; i < refs.size(); i++)
				{
					unsigned long long temp = refs[i].getHex();
					result.push_back(temp >> 0x20);
					result.push_back(temp);
				}

				return result;
			}
			bool brawlReferenceVector::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;

				if (destinationStream.good())
				{
					std::vector<unsigned long> hexBufferVector = getHex();
					for (std::size_t i = 0; i < hexBufferVector.size(); i++)
					{
						lava::writeRawDataToStream(destinationStream, hexBufferVector[i]);
					}
					result = destinationStream.good();
				}

				return result;
			}

			/* Brawl Reference */



			/* BRSAR Symb Section */

			bool brsarSymbMaskEntry::populate(lava::byteArray& bodyIn, unsigned long addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					flags = bodyIn.getShort(addressIn);
					bit = bodyIn.getShort(addressIn + 0x02);
					leftID = bodyIn.getLong(address + 0x04);
					rightID = bodyIn.getLong(address + 0x08);
					stringID = bodyIn.getLong(address + 0x0C);
					index = bodyIn.getLong(address + 0x10);

					result = 1;
				}

				return result;
			}
			bool brsarSymbMaskHeader::populate(lava::byteArray& bodyIn, unsigned long addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					rootID = bodyIn.getLong(address);
					numEntries = bodyIn.getLong(address + 0x04);

					unsigned long cursor = address + 0x08;
					unsigned long cursorMax = cursor + (0x14 * numEntries);

					std::size_t i = 0;
					entries.resize(numEntries);

					while (cursor < cursorMax)
					{
						entries[i].populate(bodyIn, cursor);
						cursor += 0x14;
						i++;
					}


					result = 1;
				}

				return result;
			}

			bool brsarSymbSection::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					stringOffset = bodyIn.getLong(address + 0x08);
					soundsOffset = bodyIn.getLong(address + 0x0C);
					typesOffset = bodyIn.getLong(address + 0x10);
					groupsOffset = bodyIn.getLong(address + 0x14);
					banksOffset = bodyIn.getLong(address + 0x18);

					soundsMaskHeader.populate(bodyIn, address + 0x08 + soundsOffset);
					typesMaskHeader.populate(bodyIn, address + 0x08 + typesOffset);
					groupsMaskHeader.populate(bodyIn, address + 0x08 + groupsOffset);
					banksMaskHeader.populate(bodyIn, address + 0x08 + banksOffset);

					unsigned long cursor = address + 0x08 + stringOffset;
					stringOffsets.resize(bodyIn.getLong(cursor), ULONG_MAX);
					cursor += 0x04;
					for (std::size_t i = 0; i < stringOffsets.size(); i++)
					{
						stringOffsets[i] = bodyIn.getLong(cursor);
						cursor += 0x04;
					}

					result = 1;
				}
				return result;
			}

			/* BRSAR Symb Section */



			/* BRSAR Info Section */

			bool brsarInfoSoundEntry::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					stringID = bodyIn.getLong(address);
					fileID = bodyIn.getLong(address + 0x04);
					playerID = bodyIn.getLong(address + 0x08);
					param3DRefOffset = brawlReference(address + 0x0C);
					volume = bodyIn.getChar(address + 0x14);
					playerPriority = bodyIn.getChar(address + 0x15);
					soundType = bodyIn.getChar(address + 0x16);
					remoteFilter = bodyIn.getChar(address + 0x17);
					soundInfoRef = brawlReference(address + 0x18);
					userParam1 = bodyIn.getLong(address + 0x20);
					userParam2 = bodyIn.getLong(address + 0x24);
					panMode = bodyIn.getChar(address + 0x28);
					panCurve = bodyIn.getChar(address + 0x29);
					actorPlayerID = bodyIn.getChar(address + 0x2A);
					reserved = bodyIn.getChar(address + 0x2B);
				}

				return result;
			}

			bool brsarInfoFileEntry::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					groupID = bodyIn.getLong(address);
					index = bodyIn.getLong(address + 0x04);
				}

				return result;
			}
			bool brsarInfoFileHeader::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					headerLength = bodyIn.getLong(address);
					dataLength = bodyIn.getLong(address + 0x04);
					entryNumber = bodyIn.getLong(address + 0x08);
					stringOffset = brawlReference(bodyIn.getLLong(address + 0x0C));
					listOffset = brawlReference(bodyIn.getLLong(address + 0x14));
				}

				return result;
			}

			bool brsarInfoGroupEntry::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					fileID = bodyIn.getLong(address);
					headerOffset = bodyIn.getLong(address + 0x04);
					headerLength = bodyIn.getLong(address + 0x08);
					dataOffset = bodyIn.getLong(address + 0x0C);
					dataLength = bodyIn.getLong(address + 0x10);
					reserved = bodyIn.getLong(address + 0x14);

					result = 1;
				}

				return result;
			}
			bool brsarInfoGroupEntry::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					lava::writeRawDataToStream(destinationStream, fileID);
					lava::writeRawDataToStream(destinationStream, headerOffset);
					lava::writeRawDataToStream(destinationStream, headerLength);
					lava::writeRawDataToStream(destinationStream, dataOffset);
					lava::writeRawDataToStream(destinationStream, dataLength);
					lava::writeRawDataToStream(destinationStream, reserved);

					result = destinationStream.good();
				}
				return result;
			}
			bool brsarInfoGroupHeader::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					stringID = bodyIn.getLong(address);
					entryNum = bodyIn.getLong(address + 0x04);
					extFilePathRef = brawlReference(bodyIn.getLLong(address + 0x08));
					headerOffset = bodyIn.getLong(address + 0x10);
					headerLength = bodyIn.getLong(address + 0x14);
					waveDataOffset = bodyIn.getLong(address + 0x18);
					waveDataLength = bodyIn.getLong(address + 0x1C);
					listOffset = brawlReference(bodyIn.getLLong(address + 0x20));

					result = 1;
				}

				return result;
			}
			bool brsarInfoGroupHeader::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					lava::writeRawDataToStream(destinationStream, stringID);
					lava::writeRawDataToStream(destinationStream, entryNum);
					lava::writeRawDataToStream(destinationStream, extFilePathRef.getHex());
					lava::writeRawDataToStream(destinationStream, headerOffset);
					lava::writeRawDataToStream(destinationStream, headerLength);
					lava::writeRawDataToStream(destinationStream, waveDataOffset);
					lava::writeRawDataToStream(destinationStream, waveDataLength);
					lava::writeRawDataToStream(destinationStream, listOffset.getHex());

					result = destinationStream.good();
				}
				return result;
			}

			std::vector<brsarInfoFileHeader*> brsarInfoSection::findFilesWithGroupID(lava::byteArray& bodyIn, unsigned long groupIDIn)
			{
				std::vector<brsarInfoFileHeader*> result{};

				if (bodyIn.populated())
				{
					brsarInfoFileHeader* currHeader = nullptr;
					for (std::size_t i = 0; i < fileHeaders.size(); i++)
					{
						currHeader = &fileHeaders[i];
						for (std::size_t u = 0; u < currHeader->entries.size(); u++)
						{
							if (currHeader->entries[u].groupID == groupIDIn)
							{
								result.push_back(currHeader);
							}
						}
					}
				}

				return result;
			}

			bool brsarInfoSection::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					soundsSectionReference = brawlReference(bodyIn.getLLong(address + 0x08));
					banksSectionReference = brawlReference(bodyIn.getLLong(address + 0x10));
					playerSectionReference = brawlReference(bodyIn.getLLong(address + 0x18));
					filesSectionReference = brawlReference(bodyIn.getLLong(address + 0x20));
					groupsSectionReference = brawlReference(bodyIn.getLLong(address + 0x28));

					soundsSection.populate(bodyIn, soundsSectionReference.getAddress(address + 0x08));
					banksSection.populate(bodyIn, banksSectionReference.getAddress(address + 0x08));
					playerSection.populate(bodyIn, playerSectionReference.getAddress(address + 0x08));
					filesSection.populate(bodyIn, filesSectionReference.getAddress(address + 0x08));
					groupsSection.populate(bodyIn, groupsSectionReference.getAddress(address + 0x08));

					soundEntries.resize(soundsSection.refs.size());
					for (std::size_t i = 0; i < soundsSection.refs.size(); i++)
					{
						soundEntries[i].populate(bodyIn, soundsSection.refs[i].getAddress(address + 0x08));
					}

					fileHeaders.resize(filesSection.refs.size());
					brsarInfoFileHeader* currHeader = nullptr;
					for (std::size_t i = 0; i < filesSection.refs.size(); i++)
					{
						currHeader = &fileHeaders[i];
						currHeader->populate(bodyIn, filesSection.refs[i].getAddress(address + 0x08));
						brawlReferenceVector temp;
						temp.populate(bodyIn, currHeader->listOffset.getAddress(address + 0x08));

						for (std::size_t u = 0; u < temp.refs.size(); u++)
						{
							currHeader->entries.push_back(brsarInfoFileEntry());
							currHeader->entries.back().populate(bodyIn, temp.refs[u].getAddress(address + 0x08));
						}
					}

					result = 1;
				}

				return result;
			}

			/* BRSAR Info Section */



			/* BRSAR File Section */

			/* RWSD */
			void dataInfo::copyOverDataInfoProperties(const dataInfo& sourceInfo)
			{
				address = _NOT_IN_FILE_ADDRESS;

				wsdPitch = sourceInfo.wsdPitch;
				wsdPan = sourceInfo.wsdPan;
				wsdSurroundPan = sourceInfo.wsdSurroundPan;
				wsdFxSendA = sourceInfo.wsdFxSendA;
				wsdFxSendB = sourceInfo.wsdFxSendB;
				wsdFxSendC = sourceInfo.wsdFxSendC;
				wsdMainSend = sourceInfo.wsdMainSend;
				wsdPad1 = sourceInfo.wsdPad1;
				wsdPad2 = sourceInfo.wsdPad2;

				ttPosition = sourceInfo.ttPosition;
				ttLength = sourceInfo.ttLength;
				ttNoteIndex = sourceInfo.ttNoteIndex;

				ntAttack = sourceInfo.ntAttack;
				ntDecay = sourceInfo.ntDecay;
				ntSustain = sourceInfo.ntSustain;
				ntRelease = sourceInfo.ntRelease;
				ntHold = sourceInfo.ntHold;
				ntPad1 = sourceInfo.ntPad1;
				ntPad2 = sourceInfo.ntPad2;
				ntPad3 = sourceInfo.ntPad3;
				ntOriginalKey = sourceInfo.ntOriginalKey;
				ntVolume = sourceInfo.ntVolume;
				ntPan = sourceInfo.ntPan;
				ntSurroundPan = sourceInfo.ntSurroundPan;
				ntPitch = sourceInfo.ntPitch;
			}

			bool dataInfo::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;
					wsdInfo = brawlReference(bodyIn.getLLong(address));
					trackTable = brawlReference(bodyIn.getLLong(address + 0x08));
					noteTable = brawlReference(bodyIn.getLLong(address + 0x10));

					wsdPitch = bodyIn.getFloat(address + 0x18);
					wsdPan = bodyIn.getChar(address + 0x1C);
					wsdSurroundPan = bodyIn.getChar(address + 0x1D);
					wsdFxSendA = bodyIn.getChar(address + 0x1E);
					wsdFxSendB = bodyIn.getChar(address + 0x1F);
					wsdFxSendC = bodyIn.getChar(address + 0x20);
					wsdMainSend = bodyIn.getChar(address + 0x21);
					wsdPad1 = bodyIn.getChar(address + 0x22);
					wsdPad2 = bodyIn.getChar(address + 0x23);
					wsdGraphEnvTableRef = brawlReference(bodyIn.getLLong(address + 0x24));
					wsdRandomizerTableRef = brawlReference(bodyIn.getLLong(address + 0x2C));
					wsdPadding = bodyIn.getLong(address + 0x34);

					ttReferenceList1.populate(bodyIn, address + 0x38);
					ttIntermediateReference = brawlReference(bodyIn.getLLong(address + 0x44));
					ttReferenceList2.populate(bodyIn, address + 0x4C);
					ttPosition = bodyIn.getFloat(address + 0x58);
					ttLength = bodyIn.getFloat(address + 0x5C);
					ttNoteIndex = bodyIn.getLong(address + 0x60);
					ttReserved = bodyIn.getLong(address + 0x64);

					ntReferenceList.populate(bodyIn, address + 0x68);
					ntWaveIndex = bodyIn.getLong(address + 0x74);
					ntAttack = bodyIn.getChar(address + 0x78);
					ntDecay = bodyIn.getChar(address + 0x79);
					ntSustain = bodyIn.getChar(address + 0x7A);
					ntRelease = bodyIn.getChar(address + 0x7B);
					ntHold = bodyIn.getChar(address + 0x7C);
					ntPad1 = bodyIn.getChar(address + 0x7D);
					ntPad2 = bodyIn.getChar(address + 0x7E);
					ntPad3 = bodyIn.getChar(address + 0x7F);
					ntOriginalKey = bodyIn.getChar(address + 0x80);
					ntVolume = bodyIn.getChar(address + 0x81);
					ntPan = bodyIn.getChar(address + 0x82);
					ntSurroundPan = bodyIn.getChar(address + 0x83);
					ntPitch = bodyIn.getFloat(address + 0x84);
					ntIfoTableRef = brawlReference(bodyIn.getLLong(address + 0x88));
					ntGraphEnvTableRef = brawlReference(bodyIn.getLLong(address + 0x90));
					ntRandomizerTableRef = brawlReference(bodyIn.getLLong(address + 0x98));
					ntReserved = bodyIn.getLong(address + 0xA0);

					result = 1;
				}

				return result;
			}
			bool dataInfo::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					lava::writeRawDataToStream(destinationStream, wsdInfo.getHex());
					lava::writeRawDataToStream(destinationStream, trackTable.getHex());
					lava::writeRawDataToStream(destinationStream, noteTable.getHex());
					lava::writeRawDataToStream(destinationStream, wsdPitch);
					lava::writeRawDataToStream(destinationStream, wsdPan);
					lava::writeRawDataToStream(destinationStream, wsdSurroundPan);
					lava::writeRawDataToStream(destinationStream, wsdFxSendA);
					lava::writeRawDataToStream(destinationStream, wsdFxSendB);
					lava::writeRawDataToStream(destinationStream, wsdFxSendC);
					lava::writeRawDataToStream(destinationStream, wsdMainSend);
					lava::writeRawDataToStream(destinationStream, wsdPad1);
					lava::writeRawDataToStream(destinationStream, wsdPad2);
					lava::writeRawDataToStream(destinationStream, wsdGraphEnvTableRef.getHex());
					lava::writeRawDataToStream(destinationStream, wsdRandomizerTableRef.getHex());
					lava::writeRawDataToStream(destinationStream, wsdPadding);

					ttReferenceList1.exportContents(destinationStream);
					lava::writeRawDataToStream(destinationStream, ttIntermediateReference.getHex());
					ttReferenceList2.exportContents(destinationStream);
					lava::writeRawDataToStream(destinationStream, ttPosition);
					lava::writeRawDataToStream(destinationStream, ttLength);
					lava::writeRawDataToStream(destinationStream, ttNoteIndex);
					lava::writeRawDataToStream(destinationStream, ttReserved);

					ntReferenceList.exportContents(destinationStream);
					lava::writeRawDataToStream(destinationStream, ntWaveIndex);
					lava::writeRawDataToStream(destinationStream, ntAttack);
					lava::writeRawDataToStream(destinationStream, ntDecay);
					lava::writeRawDataToStream(destinationStream, ntSustain);
					lava::writeRawDataToStream(destinationStream, ntRelease);
					lava::writeRawDataToStream(destinationStream, ntHold);
					lava::writeRawDataToStream(destinationStream, ntPad1);
					lava::writeRawDataToStream(destinationStream, ntPad2);
					lava::writeRawDataToStream(destinationStream, ntPad3);
					lava::writeRawDataToStream(destinationStream, ntOriginalKey);
					lava::writeRawDataToStream(destinationStream, ntVolume);
					lava::writeRawDataToStream(destinationStream, ntPan);
					lava::writeRawDataToStream(destinationStream, ntSurroundPan);
					lava::writeRawDataToStream(destinationStream, ntPitch);
					lava::writeRawDataToStream(destinationStream, ntIfoTableRef.getHex());
					lava::writeRawDataToStream(destinationStream, ntGraphEnvTableRef.getHex());
					lava::writeRawDataToStream(destinationStream, ntRandomizerTableRef.getHex());
					lava::writeRawDataToStream(destinationStream, ntReserved);

					result = destinationStream.good();
				}
				return result;
			}
			bool rwsdDataSection::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;
					length = bodyIn.getLong(addressIn + 0x04);
					entryReferences.populate(bodyIn, addressIn + 0x08);
					std::vector<brawlReference>* refVecPtr = &entryReferences.refs;
					std::size_t entryCount = refVecPtr->size();
					unsigned long entryTargetAddress = ULONG_MAX;
					entries.resize(entryCount);
					for (std::size_t i = 0; i < entryCount; i++)
					{
						entryTargetAddress = address + 0x08 + refVecPtr->at(i).getAddress();
						if (bodyIn.getLong(entryTargetAddress) == 0x01000000)
						{
							entries[i].populate(bodyIn, entryTargetAddress);
						}
						else
						{
							std::cerr << "Skipping Data Entry @ " << entryTargetAddress << "\n";
						}
					}

					result = 1;
				}

				return result;
			}
			bool rwsdDataSection::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					unsigned long initialStreamPos = destinationStream.tellp();
					destinationStream << "DATA";
					lava::writeRawDataToStream(destinationStream, length);
					entryReferences.exportContents(destinationStream);
					for (std::size_t i = 0; i < entries.size(); i++)
					{
						entries[i].exportContents(destinationStream);
					}
					unsigned long finalStreamPos = destinationStream.tellp();
					unsigned long lengthOfExport = finalStreamPos - initialStreamPos;
					if (lengthOfExport != length)
					{
						std::cerr << "Export length != length! Something may have gone wrong somewhere.\n";
						if (lengthOfExport < length)
						{
							std::vector<char> padding{};
							padding.resize(length - lengthOfExport, 0x00);
							destinationStream.write(padding.data(), padding.size());
						}
					}
					result = destinationStream.good();
				}
				return result;
			}

			bool wavePacket::populate(lava::byteArray& bodyIn, unsigned long addressIn, unsigned long lengthIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;
					length = lengthIn;

					std::size_t numGotten = SIZE_MAX;
					body = bodyIn.getBytes(lengthIn, addressIn, numGotten);
					result = numGotten == lengthIn;
					populated = result;
					if (!result)
					{
						length = ULONG_MAX;
						address = ULONG_MAX;
						body.clear();
					}
				}

				return result;
			}

			/*waveInfo::waveInfo(const waveInfo& rightHand) 
			{
				copyOverWaveInfoProperties(rightHand);
				address = rightHand.address;
			}*/
			unsigned long waveInfo::getLengthInBytes() const
			{
				unsigned long result = ULONG_MAX;

				if (address != ULONG_MAX)
				{
					auto divResult = ldiv(nibbles, 2);
					result = divResult.quot + divResult.rem;
				}

				return result;
			}
			void waveInfo::copyOverWaveInfoProperties(const waveInfo& sourceInfo)
			{
				address = _NOT_IN_FILE_ADDRESS;

				encoding = sourceInfo.encoding;
				looped = sourceInfo.looped;
				channels = sourceInfo.channels;
				sampleRate24 = sourceInfo.sampleRate24;
				sampleRate = sourceInfo.sampleRate;
				//dataLocationType = sourceInfo.dataLocationType;
				pad = sourceInfo.pad;
				loopStartSample = sourceInfo.loopStartSample;
				nibbles = sourceInfo.nibbles;
				channelInfoTableOffset = sourceInfo.channelInfoTableOffset;
				//dataLocation = sourceInfo.dataLocation;
				reserved = sourceInfo.reserved;

				channelInfoTableLength = sourceInfo.channelInfoTableLength;
				channelInfoTable = sourceInfo.channelInfoTable;
			}
			bool waveInfo::populate(lava::byteArray& bodyIn, unsigned long addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					encoding = bodyIn.getChar(address);
					looped = bodyIn.getChar(address + 0x01);
					channels = bodyIn.getChar(address + 0x02);
					sampleRate24 = bodyIn.getChar(address + 0x03);
					sampleRate = bodyIn.getShort(address + 0x04);
					dataLocationType = bodyIn.getChar(address + 0x06);
					pad = bodyIn.getChar(address + 0x07);
					loopStartSample = bodyIn.getLong(address + 0x08);
					nibbles = bodyIn.getLong(address + 0x0C);
					channelInfoTableOffset = bodyIn.getLong(address + 0x10);
					dataLocation = bodyIn.getLong(address + 0x14);
					reserved = bodyIn.getLong(address + 0x18);

					channelInfoTableLength = channels * (0x20 + (encoding == 2 ? 0x30 : 0x00));
					for (unsigned long cursor = 0x0; cursor < channelInfoTableLength; cursor += 0x04)
					{
						channelInfoTable.push_back(bodyIn.getLong(address + channelInfoTableOffset + cursor));
					}
					result = 1;
				}

				return result;
			}
			bool waveInfo::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					lava::writeRawDataToStream(destinationStream, encoding);
					lava::writeRawDataToStream(destinationStream, looped);
					lava::writeRawDataToStream(destinationStream, channels);
					lava::writeRawDataToStream(destinationStream, sampleRate24);
					lava::writeRawDataToStream(destinationStream, sampleRate);
					lava::writeRawDataToStream(destinationStream, dataLocationType);
					lava::writeRawDataToStream(destinationStream, pad);
					lava::writeRawDataToStream(destinationStream, loopStartSample);
					lava::writeRawDataToStream(destinationStream, nibbles);
					lava::writeRawDataToStream(destinationStream, channelInfoTableOffset);
					lava::writeRawDataToStream(destinationStream, dataLocation);
					lava::writeRawDataToStream(destinationStream, reserved);

					for (unsigned long i = 0x0; i < channelInfoTable.size(); i++)
					{
						lava::writeRawDataToStream(destinationStream, channelInfoTable[i]);
					}

					result = destinationStream.good();
				}
				return result;
			}

			/*bool rwsdWaveSection::insertEntry(unsigned long atIndex, const waveInfo& entryIn)
			{
				bool result = 0;

				if (atIndex < entries.size())
				{
					entries.insert(entries.begin() + atIndex, entryIn);
					entries[atIndex].address = _NOT_IN_FILE_ADDRESS;
					entryIn.channelInfoTableLength;
				}

				return result;
			}*/
			void rwsdWaveSection::pushEntry(const waveInfo& entryIn)
			{
				entries.push_back(entryIn);
				entries.back().address = _NOT_IN_FILE_ADDRESS;
				if (entries.size() > 1)
				{
					waveInfo* formerFinalEntry = &entries[entries.size() - 2];
					unsigned long newDataLocation = formerFinalEntry->dataLocation + formerFinalEntry->getLengthInBytes();
					if (formerFinalEntry->packetContents.populated)
					{
						newDataLocation += formerFinalEntry->packetContents.paddingLength;
					}
					entries.back().dataLocation = newDataLocation;
				}
				else
				{
					entries.back().dataLocation = 0x00;
				}
				if (!entryOffsets.empty())
				{
					for (unsigned long i = 0; i < entryOffsets.size(); i++)
					{
						entryOffsets[i] += 0x04;
					}
					entryOffsets.push_back(entryOffsets.back() + 0x1C + entryIn.channelInfoTableLength);
				}
				else
				{
					entryOffsets.push_back(0x10);
				}
				length += 0x04 + 0x1C + entryIn.channelInfoTableLength;
			}

			bool rwsdWaveSection::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					length = bodyIn.getLong(addressIn + 0x04);
					unsigned long entryCount = bodyIn.getLong(addressIn + 0x08);

					for (unsigned long cursor = 0x0; cursor < (entryCount * 4); cursor += 0x04)
					{
						entryOffsets.push_back(bodyIn.getLong(address + 0x0C + cursor));
						entries.push_back(waveInfo());
						entries.back().populate(bodyIn, address + entryOffsets.back());
					}

					result = 1;
				}

				return result;
			}
			bool rwsdWaveSection::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					destinationStream << "WAVE";
					lava::writeRawDataToStream(destinationStream, length);
					lava::writeRawDataToStream(destinationStream, entries.size());

					for (unsigned long i = 0x0; i < entryOffsets.size(); i++)
					{
						lava::writeRawDataToStream(destinationStream, entryOffsets[i]);
					}
					for (unsigned long i = 0x0; i < entries.size(); i++)
					{
						entries[i].exportContents(destinationStream);
					}

					result = destinationStream.good();
				}
				return result;
			}

			bool rwsdHeader::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;
					endianType = bodyIn.getShort(addressIn + 0x04);
					version = bodyIn.getShort(addressIn + 0x06);
					headerLength = bodyIn.getLong(addressIn + 0x08);
					entriesOffset = bodyIn.getShort(addressIn + 0x0C);
					entriesCount = bodyIn.getShort(addressIn + 0x0E);

					dataOffset = bodyIn.getLong(addressIn + 0x10);
					dataLength = bodyIn.getLong(addressIn + 0x14);
					waveOffset = bodyIn.getLong(addressIn + 0x18);
					waveLength = bodyIn.getLong(addressIn + 0x1C);
					result = 1;
				}

				return result;
			}
			bool rwsdHeader::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;
				if (destinationStream.good())
				{
					destinationStream << "RWSD";
					lava::writeRawDataToStream(destinationStream, endianType);
					lava::writeRawDataToStream(destinationStream, version);
					lava::writeRawDataToStream(destinationStream, headerLength);
					lava::writeRawDataToStream(destinationStream, entriesOffset);
					lava::writeRawDataToStream(destinationStream, entriesCount);
					lava::writeRawDataToStream(destinationStream, dataOffset);
					lava::writeRawDataToStream(destinationStream, dataLength);
					lava::writeRawDataToStream(destinationStream, waveOffset);
					lava::writeRawDataToStream(destinationStream, waveLength);

					result = destinationStream.good();
				}
				return result;
			}

			bool rwsd::hasExclusiveWave(unsigned long dataSectionIndex)
			{
				bool result = 1;
				if (dataSectionIndex < dataSection.entries.size())
				{
					dataInfo* dataInfoEntry = &dataSection.entries[dataSectionIndex];
					unsigned long dataWaveIndex = dataInfoEntry->ntWaveIndex;

					std::size_t i = 0;
					while (result && i < dataSection.entries.size())
					{
						if (i != dataSectionIndex)
						{
							result = dataWaveIndex != dataSection.entries[i].ntWaveIndex;
						}
						i++;
					}
				}
				return result;
			}
			bool rwsd::isFirstToUseWave(unsigned long dataSectionIndex)
			{
				bool result = 1;
				if (dataSectionIndex < dataSection.entries.size())
				{
					dataInfo* dataInfoEntry = &dataSection.entries[dataSectionIndex];
					unsigned long dataWaveIndex = dataInfoEntry->ntWaveIndex;

					std::size_t i = 0;
					while (result && i < dataSectionIndex)
					{
						result = dataWaveIndex != dataSection.entries[i].ntWaveIndex;
						i++;
					}
				}
				return result;
			}
			waveInfo* rwsd::getWaveInfoAssociatedWithDataInfo(unsigned long dataSectionIndex)
			{
				waveInfo* result = nullptr;

				if (dataSectionIndex < dataSection.entries.size())
				{
					unsigned long waveIndex = dataSection.entries[dataSectionIndex].ntWaveIndex;
					if (waveIndex < waveSection.entries.size())
					{
						result = &waveSection.entries[waveIndex];
					}
				}

				return result;
			}
			bool rwsd::populateWavePacket(lava::byteArray& bodyIn, unsigned long parentGroupWaveDataAddress, unsigned long collectionDataOffset, unsigned long dataSectionIndex)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					waveInfo* associatedWaveInfo = getWaveInfoAssociatedWithDataInfo(dataSectionIndex);
					if (associatedWaveInfo != nullptr && !associatedWaveInfo->packetContents.populated)
					{
						dataInfo* associatedDataInfo = &dataSection.entries[dataSectionIndex];
						unsigned long waveDataStartLocation = parentGroupWaveDataAddress + collectionDataOffset + associatedWaveInfo->dataLocation;
						unsigned long waveDataLength = associatedWaveInfo->getLengthInBytes();
						if (waveDataStartLocation + waveDataLength < bodyIn.body.size())
						{
							result = associatedWaveInfo->packetContents.populate(bodyIn, waveDataStartLocation, waveDataLength);
							if (associatedDataInfo->ntWaveIndex < (waveSection.entries.size() - 1))
							{
								associatedWaveInfo->packetContents.paddingLength = waveSection.entries[associatedDataInfo->ntWaveIndex + 1].dataLocation - (associatedWaveInfo->dataLocation + associatedWaveInfo->getLengthInBytes());
							}
							else
							{
								associatedWaveInfo->packetContents.paddingLength = 0x10 + (0x10 - (associatedWaveInfo->packetContents.length % 0x10));
							}
						}
					}
				}
				
				return result;
			}

			signed long rwsd::overwriteSound(unsigned long dataSectionIndex, const dataInfo& dataInfoIn, const waveInfo& waveInfoIn)
			{
				long changeInWaveDataSize = LONG_MAX;

				if (waveInfoIn.packetContents.populated)
				{
					dataInfo* dataEntryPtr = &dataSection.entries[dataSectionIndex];
					dataEntryPtr->copyOverDataInfoProperties(dataInfoIn);

					if (isFirstToUseWave(dataSectionIndex))
					{
						waveInfo* associatedWaveInfo = getWaveInfoAssociatedWithDataInfo(dataSectionIndex);
						if (associatedWaveInfo != nullptr && associatedWaveInfo->packetContents.populated)
						{
							changeInWaveDataSize = ((signed long)waveInfoIn.getLengthInBytes() - (signed long)associatedWaveInfo->getLengthInBytes())
								+ ((signed long)waveInfoIn.packetContents.paddingLength - (signed long)associatedWaveInfo->packetContents.paddingLength);
							associatedWaveInfo->copyOverWaveInfoProperties(waveInfoIn);
							associatedWaveInfo->packetContents = waveInfoIn.packetContents;
							associatedWaveInfo->packetContents.address = _NOT_IN_FILE_ADDRESS;
							
							for (std::size_t i = dataEntryPtr->ntWaveIndex + 1; i < waveSection.entries.size(); i++)
							{
								waveSection.entries[i].address = _NOT_IN_FILE_ADDRESS;
								waveSection.entries[i].dataLocation += changeInWaveDataSize;
							}
						}
					}
					else
					{
						waveSection.pushEntry(waveInfoIn);
						dataEntryPtr->ntWaveIndex = waveSection.entries.size() - 1;
						header.waveLength += 0x04 + 0x1C + waveInfoIn.channelInfoTableLength;
						changeInWaveDataSize = (signed long)waveSection.entries.back().getLengthInBytes();
						changeInWaveDataSize += (signed long)waveSection.entries.back().packetContents.paddingLength;
					}
				}
				return changeInWaveDataSize;
			}

			bool rwsd::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					if (bodyIn.getLong(addressIn) == _HEX_TAG_RWSD)
					{
						address = addressIn;

						if (header.populate(bodyIn, address))
						{
							result = dataSection.populate(bodyIn, address + header.dataOffset);
							result &= waveSection.populate(bodyIn, address + header.waveOffset);
						}
					}
				}

				return result;

			}
			bool rwsd::exportContents(std::ostream& destinationStream)
			{
				bool result = 0;

				if (destinationStream.good())
				{
					destinationStream << std::hex;
					result &= header.exportContents(destinationStream);
					result &= dataSection.exportContents(destinationStream);
					result &= waveSection.exportContents(destinationStream);
				}

				return result;
			}
			bool rwsd::exportContents(std::string destinationFile)
			{
				bool result = 0;

				std::ofstream output;
				output.open(destinationFile, std::ios_base::out | std::ios_base::binary);
				if (output.is_open())
				{
					result = rwsd::exportContents(output);
				}

				return result;
			}
			/* RWSD */

			bool brsarFileSection::catalogueRWSD(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					unsigned long cursor = address + 0x20;
					unsigned long cursorMax = address + length;
					rwsd* currEntry = nullptr;

					std::vector<waveInfo>* currEntryWaveInfoVec = nullptr;
					waveInfo* currWaveInfoEntry = nullptr;

					unsigned int rwsdIndex = 0;

					while (cursor < cursorMax)
					{
						std::cout << "RWSD Entry 0x" << lava::numToHexStringWithPadding(rwsdIndex, 0x08) << " (@ 0x" << lava::numToHexStringWithPadding(cursor, 0x08) << ")\n";
						rwsdEntries.push_back(rwsd());
						currEntry = &rwsdEntries.back();
						currEntry->populate(bodyIn, cursor);
						cursor += currEntry->header.headerLength;

						if (bodyIn.getLong(cursor) != _HEX_TAG_RWSD)
						{
							currEntryWaveInfoVec = &currEntry->waveSection.entries;

							for (std::size_t i = 0; i < currEntry->waveSection.entries.size(); i++)
							{
								currWaveInfoEntry = &(*currEntryWaveInfoVec)[i];
								std::cout << "Data Location: 0x" << lava::numToHexStringWithPadding(cursor + currWaveInfoEntry->dataLocation, 0x08);
								std::cout << " + Bytes: 0x" << lava::numToHexStringWithPadding(currWaveInfoEntry->nibbles / 2, 0x08);
								std::cout << " = 0x" << lava::numToHexStringWithPadding(cursor + currWaveInfoEntry->dataLocation + (currWaveInfoEntry->nibbles / 2), 0x08) << "\n";
							}

							cursor += currEntryWaveInfoVec->back().dataLocation + (currEntryWaveInfoVec->back().nibbles / 2);
							if (cursor % 0x10)
							{
								cursor += 0x10 - (cursor % 0x10);
							}

							// 0x52575344 == RWSD in hex, it's the hex tag for a new RWSD section
							while (bodyIn.getLong(cursor) != _HEX_TAG_RWSD)
							{
								cursor += 0x04;
							}
						}
						else
						{
							std::cout << "No entries?\n";
						}

						rwsdIndex++;

					}

				}

				return result;
			}
			bool brsarFileSection::catalogueRWSDCheat(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					unsigned long cursor = addressIn;
					unsigned long cursorMax = address + length;
					rwsd* currEntry = nullptr;

					std::vector<std::size_t> rwsdLocations = bodyIn.searchMultiple({ 0x52, 0x57, 0x53, 0x44, 0xFE, 0xFF }, cursor, cursorMax);

					rwsdEntries.resize(rwsdLocations.size());
					for (std::size_t i = 0; i < rwsdLocations.size(); i++)
					{
						std::cout << lava::numToHexStringWithPadding(i, 0x04) << " / " << lava::numToHexStringWithPadding(rwsdLocations.size(), 0x04) <<
							" (0x" << lava::numToHexStringWithPadding(rwsdLocations[i], 0x08) << ")\n";
						currEntry = &rwsdEntries[i];
						currEntry->populate(bodyIn, rwsdLocations[i]);
					}
					result = 1;
				}

				return result;
			}
			bool brsarFileSection::populate(lava::byteArray& bodyIn, std::size_t addressIn)
			{
				bool result = 0;

				if (bodyIn.populated())
				{
					address = addressIn;

					length = bodyIn.getLong(address + 0x04);

					//catalogueRWSDCheat(bodyIn, address + 0x20);
					//int test = 1;
				}

				return result;
			}

			/* BRSAR File Section */



			/* BRSAR */

			bool groupPortBundle::populateWavePacket(lava::byteArray& bodyIn, unsigned long collectionIndex, unsigned long dataEntryIndex)
			{
				bool result = 0;

				if (populatedSuccessfully)
				{
					if (collectionIndex < collections.size())
					{
						result = collectionRWSDs[collectionIndex].populateWavePacket(bodyIn, groupHeader.waveDataOffset, collections[collectionIndex].dataOffset, dataEntryIndex);
					}
				}

				return result;
			}
			bool groupPortBundle::populateAllWavePackets(lava::byteArray& bodyIn)
			{
				bool result = 0;

				if (populatedSuccessfully)
				{
					for (unsigned long i = 0; i < collectionRWSDs.size(); i++)
					{
						std::vector<dataInfo>* dataVector = &collectionRWSDs[i].dataSection.entries;
						for (unsigned long u = 0; u < dataVector->size(); u++)
						{
							if (i == 0 && u == 0x2E)
							{
								int test = 1;
							}
							populateWavePacket(bodyIn, i, u);
						}
					}
				}

				return result;
			}
			bool groupPortBundle::exportAsSawnd(std::ostream& outputStream)
			{
				bool result = 0;
				lava::writeRawDataToStream(outputStream, char(0x02));
				lava::writeRawDataToStream(outputStream, groupHeader.stringID);
				lava::writeRawDataToStream(outputStream, groupHeader.waveDataLength);

				for (unsigned long i = 0; i < collections.size(); i++)
				{
					brsarInfoGroupEntry* currEntry = &collections[i];
					lava::writeRawDataToStream(outputStream, currEntry->fileID);
					lava::writeRawDataToStream(outputStream, currEntry->dataOffset);
					lava::writeRawDataToStream(outputStream, currEntry->dataLength);
				}
				for (unsigned long i = 0; i < collectionRWSDs.size(); i++)
				{
					collectionRWSDs[i].exportContents(outputStream);
					unsigned long currentOutputPosition = outputStream.tellp();
					unsigned long paddingLength = (0x10 - (currentOutputPosition % 0x10)) + 0x01;
					std::vector<char> padding{};
					padding.resize(paddingLength, 0x00);
					outputStream.write(padding.data(), padding.size());
				}
				for (unsigned long i = 0; i < collectionRWSDs.size(); i++)
				{
					rwsd* currRWSD = &collectionRWSDs[i];
					for (unsigned long u = 0; u < currRWSD->waveSection.entries.size(); u++)
					{
						waveInfo* currEntry = &currRWSD->waveSection.entries[u];
						if (currEntry->packetContents.populated)
						{
							//std::cout << "Collection " << i << ", Wave 0x" << lava::numToHexStringWithPadding(u, 0x04) << "\n";
							//std::cout << "\tOutput Stream Pos: 0x" << lava::numToHexStringWithPadding(outputStream.tellp(), 0x08) << "\n";
							std::vector<char>* currEntryPacketBodyPtr = (std::vector<char>*) & currEntry->packetContents.body;
							outputStream.write(currEntryPacketBodyPtr->data(), currEntryPacketBodyPtr->size());
							//std::cout << "\tOutput Stream Pos (Post Data-Write): 0x" << lava::numToHexStringWithPadding(outputStream.tellp(), 0x08) << "\n";
							std::vector<char> padding{};
							if (currEntry->packetContents.paddingLength == ULONG_MAX)
							{
								std::cerr << "Padding length not initialized properly.\n";
							}
							padding.resize(currEntry->packetContents.paddingLength, 0x00);
							outputStream.write(padding.data(), padding.size());
							//std::cout << "\tOutput Stream Pos (Post Pad-Write): 0x" << lava::numToHexStringWithPadding(outputStream.tellp(), 0x08) << "\n";
						}
						else
						{
							std::cerr << "Couldn't Export Wave Data for Collection " << i << ", Wave #" << u << "\n";
							std::cerr << "Packet contents not populated.\n";
						}
					}
				}

				result = outputStream.good();
				return result;
			}

			bool groupPortSoundCorrespondence::outputCorrespondenceData(std::ostream& output)
			{
				bool result = 0;

				if (output.good())
				{
					std::map<unsigned long, unsigned long> sortedIndeces{};
					for (auto i : matches)
					{
						if (i.second.sourceGroupDataIndex.first != ULONG_MAX && i.second.sourceGroupDataIndex.second != ULONG_MAX)
						{
							sortedIndeces[i.second.sourceGroupInfoIndex] = i.second.destinationGroupInfoIndex;
						}
					}
					for (auto i : sortedIndeces)
					{
						output << "0x" << lava::numToHexStringWithPadding(i.first, 0x04) << " 0x" << lava::numToHexStringWithPadding(i.second, 0x04) << "\n";
					}
				}

				return result;
			}

			bool brsarFile::init(std::string filePathIn)
			{
				bool result = 0;
				std::ifstream fileIn;
				fileIn.open(filePathIn, std::ios_base::in | std::ios_base::binary);
				if (fileIn.is_open())
				{
					result = 1;
					contents.populate(fileIn);
					std::size_t tempNumber = 0;

					symbSection.populate(contents, contents.getLong(0x10));
					infoSection.populate(contents, contents.getLong(0x18));
					fileSection.populate(contents, contents.getLong(0x20));

					//listSoundsInGroup(0x08);
				}
				return result;
			}

			std::string brsarFile::getSymbString(unsigned long indexIn)
			{
				std::string result = "";

				if (contents.populated())
				{
					if (indexIn < symbSection.stringOffsets.size())
					{
						char* ptr = contents.body.data() + symbSection.address + 0x08 + symbSection.stringOffsets[indexIn];
						result = std::string(ptr);
					}
				}

				return result;
			}
			bool brsarFile::summarizeSymbStringData(std::ostream& output)
			{
				bool result = 0;

				if (output.good() && symbSection.address != ULONG_MAX)
				{
					unsigned long stringOffset = ULONG_MAX;
					unsigned long stringAddress = ULONG_MAX;
					unsigned long stringOffsetAddress = symbSection.address + 0x08 + symbSection.stringOffset + 0x04;
					for (std::size_t i = 0; i < symbSection.stringOffsets.size(); i++)
					{
						stringOffset = symbSection.stringOffsets[i];
						stringAddress = symbSection.address + stringOffset + 0x08;
						char* ptr = contents.body.data() + stringAddress;
						output << "[0x" << lava::numToHexStringWithPadding(i, 4) << "] 0x" << lava::numToHexStringWithPadding(stringOffsetAddress, 4) << "->0x" << lava::numToHexStringWithPadding(stringAddress, 4) << ": " << ptr << "\n";
						stringOffsetAddress += 0x04;
					}

				}

				return result;
			}
			bool brsarFile::outputConsecutiveSoundEntryStringsWithSameFileID(unsigned long startingIndex, std::ostream& output)
			{
				bool result = 0;

				if (output.good() && symbSection.address != ULONG_MAX)
				{
					unsigned long fileID = infoSection.soundEntries[startingIndex].fileID;
					std::size_t i = startingIndex;
					while (i < infoSection.soundEntries.size() && infoSection.soundEntries[i].fileID == fileID)
					{
						output << "\t[String 0x" << lava::numToHexStringWithPadding(i, 0x04) << "] " << getSymbString(i) << "\n";
						i++;
					}
				}

				return result;
			}

			unsigned long brsarFile::getGroupOffset(unsigned long groupIDIn)
			{
				std::size_t result = SIZE_MAX;

				std::size_t i = 0;
				brsarInfoGroupHeader currentGroup;
				bool done = 0;

				while (!done && i < infoSection.groupsSection.refs.size())
				{
					currentGroup.populate(contents, infoSection.groupsSection.refs[i].getAddress(infoSection.address + 0x08));
					if (groupIDIn == currentGroup.stringID)
					{
						result = currentGroup.address;
						done = 1;
					}
					else
					{
						i++;
					}
				}

				return result;
			}
			bool brsarFile::listSoundsInGroup(unsigned long groupIDIn, std::ostream& output)
			{
				bool result = 0;

				if (contents.populated())
				{
					brsarInfoGroupHeader groupHeader;
					brawlReferenceVector collectionReferences;
					std::vector<brsarInfoGroupEntry> collections{};
					std::vector<unsigned long> groupEntriesFirstSoundIndex{};
					std::vector<rwsd> collectionRWSDs{};
					unsigned long groupOffset = getGroupOffset(groupIDIn);

					std::vector<brsarInfoFileEntry*> filesForGroup{};

					if (groupOffset != ULONG_MAX)
					{
						groupHeader.populate(contents, groupOffset);
						collectionReferences.populate(contents, groupHeader.listOffset.getAddress(infoSection.address + 0x08));

						// Populate the collections associated with this group.
						collections.resize(collectionReferences.refs.size());
						for (std::size_t i = 0; i < collectionReferences.refs.size(); i++)
						{
							collections[i].populate(contents, collectionReferences.refs[i].getAddress(infoSection.address + 0x08));
						}

						// Find the first Sound Entry with each collection's File ID.
						groupEntriesFirstSoundIndex.resize(collections.size(), ULONG_MAX);
						for (std::size_t u = 0; u < collections.size(); u++)
						{
							for (std::size_t i = 0; groupEntriesFirstSoundIndex[u] == ULONG_MAX && i < infoSection.soundEntries.size(); i++)
							{
								if (infoSection.soundEntries[i].fileID == collections[u].fileID)
								{
									groupEntriesFirstSoundIndex[u] = i;
								}
							}
						}

						collectionRWSDs.resize(collections.size());
						for (std::size_t i = 0; i < collections.size(); i++)
						{
							collectionRWSDs[i].populate(contents, groupHeader.headerOffset + collections[i].headerOffset);
						}

						std::vector<dataInfo>* dataVector = nullptr;
						std::vector<waveInfo>* waveVector = nullptr;
						dataInfo* dataPtr = nullptr;
						waveInfo* wavePtr = nullptr;
						unsigned long soundEffectNameIndex = ULONG_MAX;
						for (std::size_t i = 0; i < collectionRWSDs.size(); i++)
						{
							dataVector = &collectionRWSDs[i].dataSection.entries;
							waveVector = &collectionRWSDs[i].waveSection.entries;
							output << "Summary for Collection #" << i << " (File ID: 0x" << lava::numToHexStringWithPadding(collections[i].fileID, 0x04) << ")\n";
							for (std::size_t u = 0; u < dataVector->size(); u++)
							{
								dataPtr = &(*dataVector)[u];
								wavePtr = &(*waveVector)[dataPtr->ntWaveIndex];
								soundEffectNameIndex = 0x194 + groupEntriesFirstSoundIndex[i] + u;
								output << "\tSound: 0x" << lava::numToHexStringWithPadding(u, 0x04) << " (\"" <<
									shuckSoundEffectName(getSymbString(soundEffectNameIndex)) << "\")\n";
								output << "\t\tWave Index: 0x" << lava::numToHexStringWithPadding((*dataVector)[u].ntWaveIndex, 0x04) << "\n";
								output << "\t\tWave Data Offset: 0x" << lava::numToHexStringWithPadding(wavePtr->dataLocation, 0x08) << "\n";
								output << "\t\tWave Data Address: 0x" <<
									lava::numToHexStringWithPadding(groupHeader.waveDataOffset + collections[i].dataOffset + wavePtr->dataLocation, 0x08) << "\n";
								output << "\t\tWave Data Length: 0x" << lava::numToHexStringWithPadding(wavePtr->getLengthInBytes(), 0x08) << "\n";
							}
						}
					}
				}
				return result;
			}

			groupPortBundle brsarFile::getGroupPortBundle(groupFileInfo groupInfoIn)
			{
				groupPortBundle result;

				if (contents.populated())
				{
					result.groupID = groupInfoIn.groupID;
					result.groupOffset = getGroupOffset(groupInfoIn.groupID);

					if (result.groupOffset != ULONG_MAX)
					{
						result.populatedSuccessfully = 1;
						result.populatedSuccessfully &= result.groupHeader.populate(contents, result.groupOffset);
						result.populatedSuccessfully &= result.collectionReferences.populate(contents, result.groupHeader.listOffset.getAddress(infoSection.address + 0x08));

						// Populate the collections associated with this group.
						for (std::size_t i = 0; i < result.collectionReferences.refs.size(); i++)
						{
							brsarInfoGroupEntry tempEntry;
							bool populatedSuccessfully = tempEntry.populate(contents, result.collectionReferences.refs[i].getAddress(infoSection.address + 0x08));
							if (groupInfoIn.fileIDAcceptable(tempEntry.fileID))
							{
								result.collections.push_back(tempEntry);
								result.populatedSuccessfully &= populatedSuccessfully;
							}
							else
							{
								std::cerr << "\tDisallowed Collection (File ID: " << tempEntry.fileID << "), Load Skipped\n";
							}
						}

						// Find the first Sound Entry with each collection's File ID.
						result.groupEntriesFirstSoundIndex.resize(result.collections.size(), ULONG_MAX);
						for (std::size_t u = 0; u < result.collections.size(); u++)
						{
							for (std::size_t i = 0; result.groupEntriesFirstSoundIndex[u] == ULONG_MAX && i < infoSection.soundEntries.size(); i++)
							{
								if (infoSection.soundEntries[i].fileID == result.collections[u].fileID)
								{
									result.groupEntriesFirstSoundIndex[u] = i;
								}
							}
						}

						result.collectionRWSDs.resize(result.collections.size());
						for (std::size_t i = 0; i < result.collections.size(); i++)
						{
							result.populatedSuccessfully &= result.collectionRWSDs[i].populate(contents, result.groupHeader.headerOffset + result.collections[i].headerOffset);
						}
					}
				}

				return result;
			}
			groupPortSoundCorrespondence brsarFile::getGroupPortStringCorr(const groupPortBundle& sourceGroupBundle, const groupPortBundle& destinationGroupBundle)
			{
				groupPortSoundCorrespondence result;

				if (sourceGroupBundle.populatedSuccessfully)
				{
					if (destinationGroupBundle.populatedSuccessfully)
					{
						result.successfulMatches = 0;

						const std::vector<dataInfo>* dataVectorPtr = nullptr;
						const std::vector<waveInfo>* waveVectorPtr = nullptr;
						const dataInfo* dataPtr = nullptr;
						const waveInfo* wavePtr = nullptr;
						unsigned long soundEffectNameIndex = ULONG_MAX;
						groupPortEntryInfoBundle* currentEntry = nullptr;
						std::string unshuckedName = "";
						std::string shuckedName = "";
						std::unordered_map<std::string, std::string>::iterator overrideUsedReceiver = soundEffectNameOverrides.end();

						for (std::size_t i = 0; i < destinationGroupBundle.collectionRWSDs.size(); i++)
						{
							dataVectorPtr = &destinationGroupBundle.collectionRWSDs[i].dataSection.entries;
							waveVectorPtr = &destinationGroupBundle.collectionRWSDs[i].waveSection.entries;
							unsigned long firstSoundIndex = destinationGroupBundle.groupEntriesFirstSoundIndex[i];
							for (std::size_t u = 0; u < dataVectorPtr->size(); u++)
							{
								dataPtr = &(*dataVectorPtr)[u];
								wavePtr = &(*waveVectorPtr)[dataPtr->ntWaveIndex];
								soundEffectNameIndex = 0x194 + firstSoundIndex + u;
								auto emplaceResult = result.matches.emplace(std::make_pair(shuckSoundEffectName(getSymbString(soundEffectNameIndex), &overrideUsedReceiver), groupPortEntryInfoBundle()));
								currentEntry = &emplaceResult.first->second;
								currentEntry->destinationGroupDataIndex = std::make_pair(i, u);
								currentEntry->destinationGroupInfoIndex = soundEffectNameIndex - 0x194;
								currentEntry->destinationGroupDataIndexLocked = overrideUsedReceiver != soundEffectNameOverrides.end();
							}
						}
						for (std::size_t i = 0; i < sourceGroupBundle.collectionRWSDs.size(); i++)
						{
							dataVectorPtr = &sourceGroupBundle.collectionRWSDs[i].dataSection.entries;
							waveVectorPtr = &sourceGroupBundle.collectionRWSDs[i].waveSection.entries;
							unsigned long firstSoundIndex = sourceGroupBundle.groupEntriesFirstSoundIndex[i];
							for (std::size_t u = 0; u < dataVectorPtr->size(); u++)
							{
								shuckedName = "";
								dataPtr = &(*dataVectorPtr)[u];
								wavePtr = &(*waveVectorPtr)[dataPtr->ntWaveIndex];
								soundEffectNameIndex = 0x194 + firstSoundIndex + u;
								unshuckedName = getSymbString(soundEffectNameIndex);
								shuckedName = shuckSoundEffectName(unshuckedName, &overrideUsedReceiver);
								auto findResult = result.matches.find(shuckedName);
								if (findResult == result.matches.end())
								{
									result.sourceEntriesWithNoMatch.push_back(std::make_pair(i, u));
								}
								else
								{
									if (findResult->second.sourceGroupDataIndex.first != ULONG_MAX &&
										findResult->second.sourceGroupDataIndex.second != ULONG_MAX)
									{
										if (!findResult->second.sourceGroupDataIndexLocked)
										{
											if (overrideUsedReceiver != soundEffectNameOverrides.end())
											{
												result.sourceEntriesPushedOutByOverrides.push_back(findResult->second.sourceGroupDataIndex);
												findResult->second.sourceGroupDataIndexLocked = 1;
											}
											else
											{
												result.sourceEntriesPushedOutByOtherSounds.push_back(findResult->second.sourceGroupDataIndex);
											}
											findResult->second.sourceGroupInfoIndex = soundEffectNameIndex - 0x194;
											findResult->second.sourceGroupDataIndex = std::make_pair(i, u);
										}
										else
										{
											//std::cerr << "\tCannot overwrite entry, it's locked.\n";
											result.sourceEntriesPushedOutByOverrides.push_back(std::make_pair(i, u));
										}
									}
									else
									{
										if (overrideUsedReceiver != soundEffectNameOverrides.end())
										{
											findResult->second.sourceGroupDataIndexLocked = 1;
										}
										findResult->second.sourceGroupInfoIndex = soundEffectNameIndex - 0x194;
										findResult->second.sourceGroupDataIndex = std::make_pair(i, u);
										result.successfulMatches++;
									}
								}
							}
						}

						
					}
				}

				return result;
			}

			bool brsarFile::portCorrespondingSounds(const groupPortSoundCorrespondence& soundCorr, const groupPortBundle& sourceGroupBundle, groupPortBundle& destinationGroupBundle, bool portEmptySounds)
			{
				bool result = 0;

				if (soundCorr.successfulMatches != ULONG_MAX)
				{
					unsigned long copySourceCollIndex = ULONG_MAX;
					unsigned long copySourceDataIndex = ULONG_MAX;
					unsigned long copyDestCollIndex = ULONG_MAX;
					unsigned long copyDestDataIndex = ULONG_MAX;
					const dataInfo* copySourceData = nullptr;
					const waveInfo* copySourceWave = nullptr;
					for (auto i : soundCorr.matches)
					{
						copySourceCollIndex = i.second.sourceGroupDataIndex.first;
						copySourceDataIndex = i.second.sourceGroupDataIndex.second;
						if (copySourceCollIndex != ULONG_MAX && copySourceDataIndex != ULONG_MAX)
						{
							copyDestCollIndex = i.second.destinationGroupDataIndex.first;
							copyDestDataIndex = i.second.destinationGroupDataIndex.second;
							copySourceData = &sourceGroupBundle.collectionRWSDs[copySourceCollIndex].dataSection.entries[copySourceDataIndex];
							copySourceWave = &sourceGroupBundle.collectionRWSDs[copySourceCollIndex].waveSection.entries[copySourceData->ntWaveIndex];

							if (portEmptySounds || copySourceWave->nibbles >= 3)
							{
								unsigned long changeInSize = destinationGroupBundle.collectionRWSDs[copyDestCollIndex].overwriteSound(copyDestDataIndex, *copySourceData, *copySourceWave);
								destinationGroupBundle.groupHeader.waveDataLength += changeInSize;
								destinationGroupBundle.collections[copyDestCollIndex].dataLength += changeInSize;
								if (copyDestCollIndex < destinationGroupBundle.collections.size() - 1)
								{
									destinationGroupBundle.collections[copyDestCollIndex + 1].dataOffset += changeInSize;
								}
							}
							else
							{
								std::cerr << "Skipping empty sound!\n";
							}
						}
					}

					result = 1;
				}
				return result;
			}

			bool brsarFile::portGroupToGroup(unsigned long sourceCharFIDIn, unsigned long destinationCharFIDIn, std::ostream& contentsOutput, std::ostream& logOutput, groupPortSoundCorrespondence* soundMappingOut)
			{
				bool result = 0;

				if (contents.populated())
				{
					std::unordered_map<unsigned long, groupFileInfo>::iterator sourceGroupFileInfo = fighterIDToGroupInfoMap.find(sourceCharFIDIn);
					if (sourceGroupFileInfo != fighterIDToGroupInfoMap.end())
					{
						std::unordered_map<unsigned long, groupFileInfo>::iterator destinationGroupFileInfo = fighterIDToGroupInfoMap.find(destinationCharFIDIn);
						if (destinationGroupFileInfo != fighterIDToGroupInfoMap.end())
						{
							groupPortBundle sourceGroupBundle = getGroupPortBundle(sourceGroupFileInfo->second);
							groupPortBundle destinationGroupBundle = getGroupPortBundle(destinationGroupFileInfo->second);

							logOutput << "Porting Group #" << sourceGroupFileInfo->second.groupID << " to Group #" << destinationGroupFileInfo->second.groupID << "...\n";

							if (sourceGroupBundle.populatedSuccessfully)
							{
								if (destinationGroupBundle.populatedSuccessfully)
								{
									groupPortSoundCorrespondence soundCorr = getGroupPortStringCorr(sourceGroupBundle, destinationGroupBundle);

									if (soundCorr.successfulMatches != ULONG_MAX)
									{
										logOutput << "Successfully found destinations for " << soundCorr.successfulMatches << " sound(s).\n";
										logOutput << "Couldn't find destinations for " << soundCorr.sourceEntriesWithNoMatch.size() << " sound(s):\n";
										unsigned long soundEffectNameIndex = ULONG_MAX;
										for (std::size_t i = 0; i < soundCorr.sourceEntriesWithNoMatch.size(); i++)
										{
											std::pair<unsigned long, unsigned long>* curr = &soundCorr.sourceEntriesWithNoMatch[i];
											soundEffectNameIndex = 0x194 + sourceGroupBundle.groupEntriesFirstSoundIndex[curr->first] + curr->second;
											logOutput << "\tCollection #" << curr->first << ", Sound #" << curr->second << ": " << getSymbString(soundEffectNameIndex) << "\n";
										}
										if (!soundCorr.sourceEntriesPushedOutByOverrides.empty())
										{
											logOutput << "Overrides caused " << soundCorr.sourceEntriesPushedOutByOverrides.size() << " sound(s) to be omitted:\n";
											for (std::size_t i = 0; i < soundCorr.sourceEntriesPushedOutByOverrides.size(); i++)
											{
												std::pair<unsigned long, unsigned long>* curr = &soundCorr.sourceEntriesPushedOutByOverrides[i];
												soundEffectNameIndex = 0x194 + sourceGroupBundle.groupEntriesFirstSoundIndex[curr->first] + curr->second;
												logOutput << "\tCollection #" << curr->first << ", Sound #" << curr->second << ": " << getSymbString(soundEffectNameIndex) << "\n";
											}
										}
										if (!soundCorr.sourceEntriesPushedOutByOtherSounds.empty())
										{
											logOutput << "Non-overrides caused " << soundCorr.sourceEntriesPushedOutByOtherSounds.size() << " sound(s) to be omitted:\n";
											for (std::size_t i = 0; i < soundCorr.sourceEntriesPushedOutByOtherSounds.size(); i++)
											{
												std::pair<unsigned long, unsigned long>* curr = &soundCorr.sourceEntriesPushedOutByOtherSounds[i];
												soundEffectNameIndex = 0x194 + sourceGroupBundle.groupEntriesFirstSoundIndex[curr->first] + curr->second;
												logOutput << "\tCollection #" << curr->first << ", Sound #" << curr->second << ": " << getSymbString(soundEffectNameIndex) << "\n";
											}
										}

										sourceGroupBundle.populateAllWavePackets(contents);
										destinationGroupBundle.populateAllWavePackets(contents);

										if (portCorrespondingSounds(soundCorr, sourceGroupBundle, destinationGroupBundle, 1))
										{
											result = destinationGroupBundle.exportAsSawnd(contentsOutput);
											if (soundMappingOut != nullptr)
											{
												*soundMappingOut = soundCorr;
											}
											//buildBundleFromSawnd(lava::numToHexStringWithPadding(destinationGroupBundle.groupID, 0x3) + ".sawnd");
										}
										else
										{
											std::cerr << "Failed to port sounds, skipping export.\n";
										}
										int test = 0;
									}
								}
								else
								{
									logOutput << "Couldn't begin port, destination group couldn't be successfully parsed.\n";
								}
							}
							else
							{
								logOutput << "Couldn't begin port, source group couldn't be successfully parsed.\n";
							}
						}
					}
				}
				return result;
			}


			bool brsarFile::exportSawnd(std::size_t groupID, std::string targetFilePath)
			{
				bool result = 0;
				std::cout << "Creating \"" << targetFilePath << "\" from Group #" << groupID << "...\n";

				std::ofstream sawndOutput;
				sawndOutput.open(targetFilePath, std::ios_base::out | std::ios_base::binary);
				if (sawndOutput.is_open())
				{
					std::size_t groupOffset = getGroupOffset(groupID);
					std::cout << "\nGroup found @ 0x" << lava::numToHexStringWithPadding(groupOffset, 8) << "!\n";

					if (groupOffset != SIZE_MAX)
					{
						brsarInfoGroupHeader targetGroup;
						targetGroup.populate(contents, groupOffset);

						std::cout << "Address: 0x" << lava::numToHexStringWithPadding(targetGroup.address, 8) << "\n";
						std::cout << "Header: Offset = 0x" << lava::numToHexStringWithPadding(targetGroup.headerOffset, 8) <<
							", Length = 0x" << lava::numToHexStringWithPadding(targetGroup.headerLength, 8) << " bytes\n";
						std::cout << "Wave Data: Offset = 0x" << lava::numToHexStringWithPadding(targetGroup.waveDataOffset, 8) <<
							", Length = 0x" << lava::numToHexStringWithPadding(targetGroup.waveDataLength, 8) << " bytes\n";

						sawndOutput.put(2);
						lava::writeRawDataToStream(sawndOutput, groupID);
						lava::writeRawDataToStream(sawndOutput, targetGroup.waveDataLength);

						std::size_t collectionRefListAddress = targetGroup.listOffset.getAddress(infoSection.address + 0x08);
						brawlReferenceVector collectionReferences;
						collectionReferences.populate(contents, collectionRefListAddress);
						std::cout << "Collection List Address(0x" << lava::numToHexStringWithPadding(collectionRefListAddress, 8) << ")\n";
						std::cout << "Collection Count: " << collectionReferences.refs.size() << "\n";
						std::vector<brsarInfoGroupEntry> groupInfoEntries;
						brsarInfoGroupEntry* currEntry = nullptr;
						unsigned long currentCollectionAddress = ULONG_MAX;

						for (std::size_t i = 0; i < collectionReferences.refs.size(); i++)
						{
							currentCollectionAddress = collectionReferences.refs[i].getAddress(infoSection.address + 0x08);
							std::cout << "Collection #" << i << ": Info Section Offset = 0x" << lava::numToHexStringWithPadding(currentCollectionAddress, 8) << "\n";
							groupInfoEntries.push_back(brsarInfoGroupEntry());
							currEntry = &groupInfoEntries.back();
							currEntry->populate(contents, currentCollectionAddress);

							std::cout << "\tFile ID: 0x" << lava::numToHexStringWithPadding(currEntry->fileID, 4) << "\n";
							std::cout << "\tHeader Offset: 0x" << lava::numToHexStringWithPadding(currEntry->headerOffset, 4) << "\n";
							std::cout << "\tHeader Length: 0x" << lava::numToHexStringWithPadding(currEntry->headerLength, 4) << "\n";
							std::cout << "\tData Offset: 0x" << lava::numToHexStringWithPadding(currEntry->dataOffset, 4) << "\n";
							std::cout << "\tData Length: 0x" << lava::numToHexStringWithPadding(currEntry->dataLength, 4) << "\n";

							lava::writeRawDataToStream(sawndOutput, currEntry->fileID);
							lava::writeRawDataToStream(sawndOutput, currEntry->dataOffset);
							lava::writeRawDataToStream(sawndOutput, currEntry->dataLength);
						}

						std::cout << "Total Size:" << targetGroup.headerLength + targetGroup.waveDataLength << "\n";
						rwsd testRWSD;
						testRWSD.populate(contents, targetGroup.headerOffset);
						testRWSD.exportContents("rwsdtest.dat");
						sawndOutput.write(contents.body.data() + targetGroup.headerOffset, targetGroup.headerLength + targetGroup.waveDataLength);
					}
					else
					{
						std::cerr << "Provided group ID couldn't be located. Aborting export.\n";
						remove(targetFilePath.c_str());
					}
				}
				else
				{
					std::cerr << "Error creating .sawnd: ";
					printError(errno);
					std::cerr << "\n";
				}
				return result;
			}

			/* BRSAR */

			groupPortBundle buildBundleFromSawnd(std::string filePathIn)
			{
				groupPortBundle result;

				std::ifstream fileIn;
				fileIn.open(filePathIn, std::ios_base::in | std::ios_base::binary);
				if (fileIn.is_open())
				{
					lava::byteArray sawndFile;
					sawndFile.populate(fileIn);
					fileIn.close();
					if (sawndFile.populated())
					{
						result.groupID = sawndFile.getLong(0x01);
						result.collectionRWSDs.push_back(rwsd());
						result.collectionRWSDs.back().populate(sawndFile, 0x21);
						result.collectionRWSDs.push_back(rwsd());
						unsigned long secondRWSDStart = sawndFile.getLong(0x29) + 0x21;
						result.collectionRWSDs.back().populate(sawndFile, secondRWSDStart);
					}
				}

				return result;
			}

		}
	}
	
}