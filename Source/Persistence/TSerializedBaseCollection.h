/*
 * Persistence Library / Persistence / TSerializedBaseCollection
 *
 * Copyright (c) 2007-2016 Ondrej Sterba <osterba@inbox.com>
 *
 * https://github.com/embedded-tools/PersistenceLibrary
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 */

#ifndef TSERIALIZATIONMANAGER___H
#define TSERIALIZATIONMANAGER___H

#include "TSerializer.h"
#include "TSerializedItem.h"
#include "TCustomString.h"
#include "TXMLTalkerInterface.h"
#include "titerator.h"
#include "tobjectlist.h"
#include "EItemState.h"

#define MANAGER_BEGIN_FLAG 0xF0
#define MANAGER_END_FLAG 0xF1
#define ELEMENT_FLAG 0xF2

#ifndef TITERATOR_INHERITANCE
   #error Iterator inheritance must be turned on, see TIterator.h file
#endif

class TSerializedBaseCollection : public TXMLTalkerInterface, public TIterator, public TSerializedItem
{
	private:
		static TCustomString<XMLMAXNAMESIZE> lastName;

		void WriteXsdManagerBegin(TCustomString<XMLMAXNAMESIZE> &name, bool minOccurs);
		void WriteXsdManagerEnd(bool addUID, bool addVersion);

	protected:

		TObjectList<TSerializedBaseCollection> subManagers;
		TCustomString<XMLMAXNAMESIZE> newItemUID;
		TCustomString<XMLMAXNAMESIZE> newItemType;				
		
		virtual TSerializedItem*  CreateItem(unsigned int uid=0, unsigned short subType=0)=0;
		virtual bool	AddItem   (TSerializedItem* item)=0;
		virtual bool	RemoveItem(TSerializedItem* item)=0;
		virtual void    Clear     ()=0;

		virtual void OnStartElement ( TXMLParserInterface* Parser, const char *pszName, TXMLParamMap &attributes);
		virtual void OnEndElement   ( TXMLParserInterface* Parser, const char *pszName);
		virtual void OnCharacterData( TXMLParserInterface* Parser, const char *pszData);

		bool LoadItem();

		void SerializeHeader(unsigned short &version);
		void SerializeBody(unsigned short version);
		void SerializeFooter(unsigned short version);

		//all following methods are emp
		
		virtual unsigned long  GetUID();				
		virtual unsigned short GetSubType();		
		virtual unsigned short GetVersion();
		virtual EItemState     GetState();
		virtual void		   SetUID(unsigned long uid);
		virtual void           SetSubType(unsigned short subType);
		virtual void           SetState(EItemState state);
		

	public:
		
		TXMLTalkerInterface*		  LastXMLTalker;
		TCustomString<XMLMAXNAMESIZE> ElementName;
		TCustomString<XMLMAXNAMESIZE> ManagerName;

		TSerializedBaseCollection();

		TSerializedItem*	FindItem(unsigned int uid);

		virtual void Serialize(unsigned short version);

};





#endif
