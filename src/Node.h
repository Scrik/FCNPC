/* =========================================

		FCNPC - Fully Controllable NPC
			----------------------

	- File: Node.h
	- Author(s): OrMisicL

  =========================================*/

#ifndef NODE_H
#define NODE_H

#include "Structs.h"
#include "SANode.h"

class CPlayerData;

class CNode
{
public:
	CNode(int iNodeId);
	~CNode();

	bool Initialize();
	int  Process(CPlayerData *pPlayerData, int iPointId, int iLastPoint, int iType, CVector vecVelocity);
	int  ProcessNodeChange(CPlayerData *pPlayerData, unsigned short usLinkId, int iType, CVector vecVelocity);

	void SetPaused(bool bPaused)
	{
		m_bPaused = bPaused;
	};

	void				GetPosition(CVector *pVecPosition);

	int					GetNodesNumber()
	{
		return m_nodeHeader.ulNodesNumber;
	};
	void				GetHeaderInfo(unsigned long *pulVehicleNodes, unsigned long *pulPedNodes, unsigned long *pulNaviNodes);

	unsigned short		GetLinkId();
	unsigned short		GetAreaId();
	unsigned short		GetPointId();
	unsigned short		GetLinkCount();
	unsigned char		GetPathWidth();
	unsigned char		GetNodeType();

	unsigned short		GetLinkPoint();

	void				SetLink(unsigned short usLinkId);
	void				SetPoint(unsigned short usPointId);

private:
	int					m_iNodeId;
	FILE				*m_pFile;
	bool				m_bPaused;
	CSANodeHeader		m_nodeHeader;
	CSAPathNode			m_nodePath;
	CSALinkNode			m_nodeLink;
};

#endif
