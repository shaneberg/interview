(() => {
    'use strict';
    const axios = require('axios');

    const getDamageRelationProfile = async (type) => {
        const typeDictionary = await axios.get('https://pokeapi.co/api/v2/type/');
        const entry = typeDictionary?.data?.results?.find((item) => { return item.name === type });
        const typeInfo = entry?.url ? await axios.get(entry.url) : null;
        const damageRelations = typeInfo?.data?.['damage_relations'];

        const weakAgainst = damageRelations?.['double_damage_from']?.map((item) => { return item.name; }) ?? null;
        const strongAgainst = damageRelations?.['half_damage_from']?.map((item) => { return item.name; }) ?? null;

        return weakAgainst && strongAgainst ? { weakAgainst, strongAgainst } : null;
    };

    const formatList = (list) => {
        let result = '';

        if (list.length === 1) {
            result = `${list[0]}`;
        } else if (list.length === 2) {
            result = `${list[0]} and ${list[1]}`;
        } else if (list.length > 2) {
            for (let i = 0; i < list.length; i++) {
                if (i === list.length - 1) {
                    result += `and ${list[i]}`;
                } else {
                    result += `${list[i]}, `;
                }
            }
        } else {
            result = 'nothing';
        }

        return result;
    };

    const buildResultString = (damageRelationProfile) => {
        if (damageRelationProfile) {
            const weakAgainstString = formatList(damageRelationProfile.weakAgainst);
            const strongAgainstString = formatList(damageRelationProfile.strongAgainst);
            return `Weak against ${weakAgainstString}. Strong against ${strongAgainstString}.`;
        } else {
            return `This is not a valid Pokémon type. They are weak against everything.`
        }
    };

    const getTypeMatchupString = async (type) => {
        const profile = await getDamageRelationProfile(type);
        return buildResultString(profile);
    };

    const typeMatchup = async (type) => {
        try {
            const typeMatchupString = await getTypeMatchupString(type);
            console.log(`${typeMatchupString}\n`);
        } catch (error) {
            console.error('Error fetching damage relation information.', error);
        }
    }

    const testTypeMatchup = async (type) => {
        console.log(`typeMatchup('${type}'):`)
        return await typeMatchup(type);
    };

    const testTypeMatchups = async () => {
        await testTypeMatchup('normal');
        await testTypeMatchup('fighting');
        await testTypeMatchup('flying');
        await testTypeMatchup('poison');
        await testTypeMatchup('ground');
        await testTypeMatchup('rock');
        await testTypeMatchup('bug');
        await testTypeMatchup('ghost');
        await testTypeMatchup('steel');
        await testTypeMatchup('fire');
        await testTypeMatchup('water');
        await testTypeMatchup('grass');
        await testTypeMatchup('electric');
        await testTypeMatchup('psychic');
        await testTypeMatchup('ice');
        await testTypeMatchup('dragon');
        await testTypeMatchup('dark');
        await testTypeMatchup('fairy');
        await testTypeMatchup('unknown');
        await testTypeMatchup('shadow');
        await testTypeMatchup('cassidy');
    };

    testTypeMatchups();
})();
