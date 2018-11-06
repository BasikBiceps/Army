========================================================================
                        The essence of the task
========================================================================
Войска.

Базовые типы юнитов:
- Unit: Абстрактный воин специализирующийся на нанесении физического урона
- SpellCaster: Абстрактный воин специализирующийся на нанесении магического урона

Вполне логично, что все юниты, наносящие магический урон способны наносить и физический. Физический урон, который наносит SpellCaster должен быть небольшим, так же SpellCaster имеет меньшее, по сравнению с Unit, количество очков здоровья.

Юниты, наносящие физический урон:
- Soldier [Солдат] : юнит без всяких специальных возможностей
- Rogue [Разбойник] : разбойника невозможно контратаковать
- Berserker [Берсерк] : на берсеркера не действует магия
- Vampire [Вампир] : при атаке / контратаке потребляет часть жизненных сил противника
- Werewolf [Оборотень] : умеет превращаться в волка (в состоянии волка имеет более высокий показатель жизненных сил и атаки, но получает больший урон от магии)

Юниты, способные к магии:
- Wizard [Волшебник] : атакует боевыми заклинаниями (лечебные заклинания имеют только половину силы)
- Healer [Целитель] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы)
- Priest [Священник] : владеет целебными заклинаниями (боевые заклинания имеют только половину силы), наносит x2 урон нежити (Vampire, Necromancer)
- Warlock [Чернокнижник] : призывает демонов (класс Demon немного расширяет класс Soldier)
- Necromancer [Некромант] : следит за всеми кого атаковал, в случае смерти атакованого юнита, получает часть его жизненных сил

Интерфейсы:
- Observer [наблюдатель] : пригодится для Necromancer
- Observable [наблюдаемое] : пригодится для всех остальных

Напрячь мозг и:
- Вынести механику атаки в виде отдельных классов
- Вынести заклинания в виде отдельных классов
- Вынести состояния юнитов в виде отдельных классов

- Придумать внятную систему разделения боевых магов и целителей
- Придумать внятную систему маркировки нежити

- Разделить урон на физический и магический
- Реализовать волшебникам книгу заклинаний (std::map и enum вам в этом помогут)
- Структурировать исходный код

Дополнительные возможности:
- Вампир может сделать вампиром другого юнита (исключение Werewolf)
- Оборотень может сделать оборотнем другого юнита (исключение Vampire)

========================================================================
    CONSOLE APPLICATION : ArmyV3.0 Project Overview
========================================================================

AppWizard has created this ArmyV3.0 application for you.

This file contains a summary of what you will find in each of the files that
make up your ArmyV3.0 application.


ArmyV3.0.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ArmyV3.0.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

ArmyV3.0.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ArmyV3.0.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
